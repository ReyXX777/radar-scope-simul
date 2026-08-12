#ifndef RADARMODEL_H
#define RADARMODEL_H

#include <QList>
#include <QObject>
#include <QQmlListProperty>
#include <QVariantList>
#include "Target.h"

class RadarModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(double sweepAngle READ sweepAngle WRITE setSweepAngle NOTIFY sweepAngleChanged)
    Q_PROPERTY(QQmlListProperty<Target> targets READ targets CONSTANT)
    Q_PROPERTY(QVariantList targetList READ targetList NOTIFY targetsChanged)

public:
    explicit RadarModel(QObject *parent = nullptr);

    double sweepAngle() const;
    void setSweepAngle(double angle);

    QQmlListProperty<Target> targets();
    QVariantList targetList() const;

    const QList<Target*>& rawTargetList() const;

    void addTarget(Target *t);

signals:
    void sweepAngleChanged();
    void targetPing(int targetId);
    void targetsChanged();

private:
    static void appendTarget(QQmlListProperty<Target> *list, Target *t);
    static int targetCount(QQmlListProperty<Target> *list);
    static Target *targetAt(QQmlListProperty<Target> *list, int index);

    double m_sweepAngle{0.0};
    QList<Target*> m_targets{};
};

#endif
