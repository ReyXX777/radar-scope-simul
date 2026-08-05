#include "Target.h"
#include <QtMath>

Target::Target(int id, double bearing, double range, QObject *parent)
    : QObject(parent), m_id(id), m_bearing(bearing), m_range(range) {}

void Target::setBearing(double b) {
    if (std::isnan(b)) return;
    b = fmod(b, 360.0);
    if (b < 0) b += 360.0;
    if (!qFuzzyCompare(m_bearing, b)) {
        m_bearing = b;
        emit bearingChanged();
    }
}

void Target::setRange(double r) {
    if (std::isnan(r)) return;
    r = qBound(0.0, r, 1.0);
    if (!qFuzzyCompare(m_range, r)) {
        m_range = r;
        emit rangeChanged();
    }
}