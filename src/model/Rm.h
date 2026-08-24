#ifndef RADARMODEL_H
#define RADARMODEL_H

#include <cstdint>
#include <QList>
#include <QObject>
#include <QQmlListProperty>
#include <QVariantList>
#include "T.h"

namespace model {

class RadarModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(double sweepAngle READ sweepAngle WRITE setSweepAngle NOTIFY sweepAngleChanged)
    Q_PROPERTY(QQmlListProperty<::model::Target> targets READ targets CONSTANT)
    Q_PROPERTY(QVariantList targetList READ targetList NOTIFY targetsChanged)

public:
    explicit RadarModel(::QObject *l_parent = nullptr);

    double sweepAngle() const;
    void setSweepAngle(double l_angle);

    QQmlListProperty<Target> targets();
    QVariantList targetList() const;

    const ::QList<Target*>& rawTargetList() const;

    void addTarget(Target *l_t);

signals:
    void sweepAngleChanged();
    void targetPing(::std::int32_t targetId);
    void targetsChanged();

private:
    static void appendTarget(QQmlListProperty<Target> *l_list, Target *l_t);
    static int targetCount(QQmlListProperty<Target> *l_list);
    static Target *targetAt(QQmlListProperty<Target> *l_list, int l_index);

    double m_sweepAngle{0.0e0};
    ::QList<Target*> m_targets{};
};

} // namespace model

#endif // RADARMODEL_H
