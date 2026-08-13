#ifndef T_H
#define T_H

#include <cstdint>
#include <QObject>

class Target : public QObject {
    Q_OBJECT
    Q_PROPERTY(double bearing READ bearing WRITE setBearing NOTIFY bearingChanged)
    Q_PROPERTY(double range READ range WRITE setRange NOTIFY rangeChanged)
    Q_PROPERTY(std::int32_t id READ id CONSTANT)

public:
    explicit Target(std::int32_t id, double bearing, double range, QObject *parent = nullptr);

    double bearing() const;
    void setBearing(double b);

    double range() const;
    void setRange(double r);

    std::int32_t id() const;

signals:
    void bearingChanged();
    void rangeChanged();

private:
    std::int32_t m_id{0};
    double m_bearing{0.0};
    double m_range{0.0};
};

#endif
