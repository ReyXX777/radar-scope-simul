#include "Target.h"

#include <algorithm>
#include <cmath>
#include <cstdint>

Target::Target(std::int32_t id, double bearing, double range, QObject *parent)
    : QObject{parent}
    , m_id{id}
    , m_bearing{bearing}
    , m_range{range} {}

double Target::bearing() const {
    return m_bearing;
}

void Target::setBearing(double b) {
    if (std::isnan(b) || std::isinf(b)) {
        return;
    }
    b = std::fmod(b, 360.0);
    if (b < 0.0) {
        b += 360.0;
    }
    if (std::abs(m_bearing - b) < 1e-6) {
        return;
    }
    m_bearing = b;
    emit bearingChanged();
}

double Target::range() const {
    return m_range;
}

void Target::setRange(double r) {
    if (std::isnan(r) || std::isinf(r)) {
        return;
    }
    const double clamped{std::clamp(r, 0.0, 1.0)};
    if (std::abs(m_range - clamped) < 1e-6) {
        return;
    }
    m_range = clamped;
    emit rangeChanged();
}

std::int32_t Target::id() const {
    return m_id;
}
