#include "Rc.h"

#include <cmath>
#include <cstdint>

namespace {
    constexpr std::int32_t kTimerIntervalMs{static_cast<std::int32_t>(1.6e1)};
    constexpr double kSecToMs{1.0e3};
    constexpr double kDegPerRpmSec{6.0e0};
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
    m_lastTime = 0.0e0;
    m_timer.start();
}

void RadarController::onTick() {
    if (!m_model) {
        return;
    }

    const std::int64_t elapsedMs{m_elapsed.restart()};
    const double dt{static_cast<double>(elapsedMs) / kSecToMs};
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
            const std::int32_t targetId{static_cast<std::int32_t>(target->id())};
            emit m_model->targetPing(targetId);
        }
    }
}
