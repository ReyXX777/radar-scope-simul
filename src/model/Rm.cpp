#include "Rm.h"

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>

namespace model {

namespace {
    constexpr double g_fullCircleDegrees{3.6e2};
    constexpr double g_angleEpsilon{1.0e-6};
}

RadarModel::RadarModel(::QObject *l_parent)
    : ::QObject{l_parent} {}

double RadarModel::sweepAngle() const {
    return m_sweepAngle;
}

void RadarModel::setSweepAngle(double l_angle) {
    if (::std::isnan(l_angle) || ::std::isinf(l_angle)) {
        return;
    }
    l_angle = ::std::fmod(l_angle, g_fullCircleDegrees);
    if (l_angle < 0.0e0) {
        l_angle += g_fullCircleDegrees;
    }
    if (::std::abs(m_sweepAngle - l_angle) < g_angleEpsilon) {
        return;
    }
    m_sweepAngle = l_angle;
    emit sweepAngleChanged();
}

QQmlListProperty<Target> RadarModel::targets() {
    return QQmlListProperty<Target>{
        this,
        nullptr,
        &RadarModel::appendTarget,
        &RadarModel::targetCount,
        &RadarModel::targetAt,
        nullptr
    };
}

const ::QList<Target*>& RadarModel::rawTargetList() const {
    return m_targets;
}

void RadarModel::addTarget(Target *l_t) {
    if (l_t && !m_targets.contains(l_t)) {
        m_targets.append(l_t);
        l_t->setParent(this);
        emit targetsChanged();
    }
}

void RadarModel::appendTarget(QQmlListProperty<Target> *l_list, Target *l_t) {
    if (!l_list) {
        return;
    }
    auto *l_model{::qobject_cast<RadarModel *>(l_list->object)};
    if (l_model) {
        l_model->addTarget(l_t);
    }
}

int RadarModel::targetCount(QQmlListProperty<Target> *l_list) {
    if (!l_list) {
        return static_cast<int>(0.0e0);
    }
    const auto *l_model{::qobject_cast<const RadarModel *>(l_list->object)};
    if (!l_model) {
        return static_cast<int>(0.0e0);
    }
    const auto l_size{l_model->m_targets.size()};
    if (l_size > static_cast<decltype(l_size)>(::std::numeric_limits<int>::max())) {
        return ::std::numeric_limits<int>::max();
    }
    return static_cast<int>(l_size);
}

Target *RadarModel::targetAt(QQmlListProperty<Target> *l_list, int l_index) {
    if (!l_list || l_index < static_cast<int>(0.0e0)) {
        return nullptr;
    }
    auto *l_model{::qobject_cast<RadarModel *>(l_list->object)};
    if (l_model && static_cast<::std::size_t>(l_index) < static_cast<::std::size_t>(l_model->m_targets.size())) {
        return l_model->m_targets.at(l_index);
    }
    return nullptr;
}

QVariantList RadarModel::targetList() const {
    QVariantList l_list{};
    const auto l_size{m_targets.size()};
    if (l_size > static_cast<decltype(l_size)>(::std::numeric_limits<int>::max())) {
        l_list.reserve(::std::numeric_limits<int>::max());
    } else {
        l_list.reserve(static_cast<int>(l_size));
    }
    for (auto *l_target : m_targets) {
        l_list.append(::QVariant::fromValue(l_target));
    }
    return l_list;
}

} // namespace model
