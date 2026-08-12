#include "Rm.h"

#include <cmath>

RadarModel::RadarModel(QObject *parent)
    : QObject{parent} {}

double RadarModel::sweepAngle() const {
    return m_sweepAngle;
}

void RadarModel::setSweepAngle(double angle) {
    if (std::isnan(angle)) {
        return;
    }
    angle = std::fmod(angle, 360.0);
    if (angle < 0.0) {
        angle += 360.0;
    }
    if (std::abs(m_sweepAngle - angle) < 1e-6) {
        return;
    }
    m_sweepAngle = angle;
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

const QList<Target*>& RadarModel::rawTargetList() const {
    return m_targets;
}

void RadarModel::addTarget(Target *t) {
    if (t && !m_targets.contains(t)) {
        m_targets.append(t);
        t->setParent(this);
        emit targetsChanged();
    }
}

void RadarModel::appendTarget(QQmlListProperty<Target> *list, Target *t) {
    if (!list) {
        return;
    }
    auto *model{qobject_cast<RadarModel *>(list->object)};
    if (model) {
        model->addTarget(t);
    }
}

int RadarModel::targetCount(QQmlListProperty<Target> *list) {
    if (!list) {
        return 0;
    }
    const auto *model{qobject_cast<const RadarModel *>(list->object)};
    return model ? static_cast<int>(model->m_targets.size()) : 0;
}

Target *RadarModel::targetAt(QQmlListProperty<Target> *list, int index) {
    if (!list) {
        return nullptr;
    }
    auto *model{qobject_cast<RadarModel *>(list->object)};
    if (model && index >= 0 && index < static_cast<int>(model->m_targets.size())) {
        return model->m_targets.at(index);
    }
    return nullptr;
}

QVariantList RadarModel::targetList() const {
    QVariantList list{};
    list.reserve(m_targets.size());
    for (auto *target : m_targets) {
        list.append(QVariant::fromValue(target));
    }
    return list;
}
