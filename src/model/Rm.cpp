#include "Rm.h"
#include <QtMath>

RadarModel::RadarModel(QObject *parent) : QObject(parent) {}

void RadarModel::setSweepAngle(double angle) {
    if (std::isnan(angle)) return;
    angle = fmod(angle, 360.0);
    if (angle < 0) angle += 360.0;
    if (!qFuzzyCompare(m_sweepAngle, angle)) {
        m_sweepAngle = angle;
        emit sweepAngleChanged();
    }
}

QQmlListProperty<Target> RadarModel::targets() {
    
    return QQmlListProperty<Target>(this, nullptr, &RadarModel::appendTarget,
                                    &RadarModel::targetCount, &RadarModel::targetAt, nullptr);
}

void RadarModel::addTarget(Target *t) {
    if (t && !m_targets.contains(t)) {
        m_targets.append(t);
        t->setParent(this);
        emit targetsChanged(); // Notify Repeater of new item
    }
}

void RadarModel::appendTarget(QQmlListProperty<Target> *list, Target *t) {
    auto *model = qobject_cast<RadarModel *>(list->object);
    if (model) model->addTarget(t);
}


int RadarModel::targetCount(QQmlListProperty<Target> *list) {
    auto *model = qobject_cast<RadarModel *>(list->object);
    return model ? static_cast<int>(model->m_targets.size()) : 0;
}


Target *RadarModel::targetAt(QQmlListProperty<Target> *list, int index) {
    auto *model = qobject_cast<RadarModel *>(list->object);
    return model && index >= 0 && index < static_cast<int>(model->m_targets.size())
           ? model->m_targets.at(index) : nullptr;
}


QVariantList RadarModel::targetList() const {
    QVariantList list;
    for (auto *target : m_targets) {
        list.append(QVariant::fromValue(target));
    }
    return list;
}