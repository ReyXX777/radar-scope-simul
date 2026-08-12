#ifndef T_H
#define T_H

#include <QObject>

class Target : public QObject {
    Q_OBJECT
    Q_PROPERTY(double bearing READ bearing WRITE setBearing NOTIFY bearingChanged)
    Q_PROPERTY(double range READ range WRITE setRange NOTIFY rangeChanged)
    Q_PROPERTY(int id READ id CONSTANT)

public:
    explicit Target(int id, double bearing, double range, QObject *parent = nullptr);

    double bearing() const;
    void setBearing(double b);

    double range() const;
    void setRange(double r);

    int id() const;

signals:
    void bearingChanged();
    void rangeChanged();

private:
    int m_id{0};
    double m_bearing{0.0};
    double m_range{0.0};
};

#endif
