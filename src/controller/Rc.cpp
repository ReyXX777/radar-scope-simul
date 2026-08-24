#include "Rc.h"
#include "model/Rm.h"

#include <cmath>
#include <cstdint>

namespace controller {

namespace {
    constexpr ::std::int32_t g_timerIntervalMs{static_cast<::std::int32_t>(1.6e1)};
    constexpr double g_secToMs{1.0e3};
    constexpr double g_degPerRpmSec{6.0e0};
}

RadarController::RadarController(::QObject *l_parent)
    : ::QObject{l_parent}
    , m_timer{}
    , m_elapsed{} {
    ::QObject::connect(&m_timer, &QTimer::timeout, this, &RadarController::onTick);
    m_timer.setInterval(g_timerIntervalMs);
}

void RadarController::setModel(::model::RadarModel *l_model) {
    m_model = l_model;
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

    const ::std::int64_t l_elapsedMs{m_elapsed.restart()};
    const double l_dt{static_cast<double>(l_elapsedMs) / g_secToMs};
    const double l_degreesPerSecond{m_rpm * g_degPerRpmSec};
    const double l_newAngle{m_model->sweepAngle() + (l_degreesPerSecond * l_dt)};
    m_model->setSweepAngle(l_newAngle);

    const double l_prevAngle{l_newAngle - (l_degreesPerSecond * l_dt)};

    for (const auto *l_target : m_model->rawTargetList()) {
        if (!l_target) {
            continue;
        }

        const double l_tb{l_target->bearing()};
        bool l_crossed{false};

        if (l_prevAngle <= l_tb && l_newAngle > l_tb) {
            l_crossed = true;
        }
        if (l_prevAngle > l_newAngle && (l_tb >= l_prevAngle || l_tb <= l_newAngle)) {
            l_crossed = true;
        }

        if (l_crossed) {
            const ::std::int32_t l_targetId{static_cast<::std::int32_t>(l_target->id())};
            emit m_model->targetPing(l_targetId);
        }
    }
}

} // namespace controller
