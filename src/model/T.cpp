#include "T.h"

#include <algorithm>
#include <cmath>
#include <cstdint>

namespace model {

namespace {
    constexpr double g_fullCircleDegrees{3.6e2};
    constexpr double g_epsilon{1.0e-6};
    constexpr double g_minRange{0.0e0};
    constexpr double g_maxRange{1.0e0};
}

Target::Target(::std::int32_t l_id, double l_bearing, double l_range, ::QObject *l_parent)
    : ::QObject{l_parent}
    , m_id{l_id}
    , m_bearing{l_bearing}
    , m_range{l_range} {}

double Target::bearing() const {
    return m_bearing;
}

void Target::setBearing(double l_b) {
    if (::std::isnan(l_b) || ::std::isinf(l_b)) {
        return;
    }
    l_b = ::std::fmod(l_b, g_fullCircleDegrees);
    if (l_b < 0.0e0) {
        l_b += g_fullCircleDegrees;
    }
    if (::std::abs(m_bearing - l_b) < g_epsilon) {
        return;
    }
    m_bearing = l_b;
    emit bearingChanged();
}

double Target::range() const {
    return m_range;
}

void Target::setRange(double l_r) {
    if (::std::isnan(l_r) || ::std::isinf(l_r)) {
        return;
    }
    const double l_clamped{::std::clamp(l_r, g_minRange, g_maxRange)};
    if (::std::abs(m_range - l_clamped) < g_epsilon) {
        return;
    }
    m_range = l_clamped;
    emit rangeChanged();
}

::std::int32_t Target::id() const {
    return m_id;
}

} // namespace model
