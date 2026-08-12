#include "Rc.h"

#include <cmath>

namespace {
    constexpr int kTimerIntervalMs{16};
    constexpr double kSecToMs{1000.0};
    constexpr double kDegPerRpmSec{6.0};
}

RadarController::RadarController(QObject *parent)
    : QObject{parent}
    , m_timer{}
    , m_elapsed{} {
    connect(&m_timer, &QTimer::timeout, this, &RadarController::onTick);
    m_timer.setInterval(kTimerIntervalMs);
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
    if (!m_model) {
        return;
    }

    const double dt{static_cast<double>(m_elapsed.restart()) / kSecToMs};
    const double degreesPerSecond{m_rpm * kDegPerRpmSec};
    const double newAngle{m_model->sweepAngle() + (degreesPerSecond * dt)};
    m_model->setSweepAngle(newAngle);

    const double prevAngle{newAngle - (degreesPerSecond * dt)};

    for (const auto *target : m_model->rawTargetList()) {
        if (!target) {
            continue;
        }

        const double tb{target->bearing()};
        bool crossed{false};

        if (prevAngle <= tb && newAngle > tb) {
            crossed = true;
        }
        if (prevAngle > newAngle && (tb >= prevAngle || tb <= newAngle)) {
            crossed = true;
        }

        if (crossed) {
            emit m_model->targetPing(target->id());
        }
    }
}
