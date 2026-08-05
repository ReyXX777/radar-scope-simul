#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include <cmath>

class Target : public QObject {
    Q_OBJECT
    Q_PROPERTY(double bearing READ bearing WRITE setBearing NOTIFY bearingChanged)
    Q_PROPERTY(double range READ range WRITE setRange NOTIFY rangeChanged)
    Q_PROPERTY(int id READ id CONSTANT)

public:
    explicit Target(int id, double bearing, double range, QObject *parent = nullptr);

    double bearing() const { return m_bearing; }
    void setBearing(double b);

    double range() const { return m_range; }
    void setRange(double r);

    int id() const { return m_id; }

signals:
    void bearingChanged();
    void rangeChanged();

private:
    int m_id;
    double m_bearing;
    double m_range;
};

#endif // TARGET_H