#include "RadarController.h"
#include <QtMath>

RadarController::RadarController(QObject *parent) : QObject(parent) {
    connect(&m_timer, &QTimer::timeout, this, &RadarController::onTick);
    m_timer.setInterval(16); // ~60fps
}

void RadarController::setModel(RadarModel *model) {
    m_model = model;
}

void RadarController::start() {
    m_elapsed.start();
    m_lastTime = 0.0;
    m_timer.start();
}

void RadarController::onTick() {
    if (!m_model) return;

    double dt = m_elapsed.restart() / 1000.0;
    double degreesPerSecond = m_rpm * 360.0 / 60.0;
    double newAngle = m_model->sweepAngle() + degreesPerSecond * dt;
    m_model->setSweepAngle(newAngle);

    // FIXED: Iterate over targetList() instead of QQmlListProperty
    double prevAngle = newAngle - degreesPerSecond * dt;
    for (auto *target : m_model->rawTargetList()) {
        double tb = target->bearing();
        bool crossed = false;
        if (prevAngle <= tb && newAngle > tb) crossed = true;
        if (prevAngle > newAngle && (tb >= prevAngle || tb <= newAngle)) crossed = true;
        if (crossed) emit m_model->targetPing(target->id());
    }
}