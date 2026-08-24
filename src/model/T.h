#ifndef T_H
#define T_H

#include <cstdint>
#include <QObject>

namespace model {

class Target : public QObject {
    Q_OBJECT
    Q_PROPERTY(double bearing READ bearing WRITE setBearing NOTIFY bearingChanged)
    Q_PROPERTY(double range READ range WRITE setRange NOTIFY rangeChanged)
    Q_PROPERTY(::std::int32_t id READ id CONSTANT)

public:
    explicit Target(::std::int32_t l_id, double l_bearing, double l_range, ::QObject *l_parent = nullptr);

    double bearing() const;
    void setBearing(double l_b);

    double range() const;
    void setRange(double l_r);

    ::std::int32_t id() const;

signals:
    void bearingChanged();
    void rangeChanged();

private:
    ::std::int32_t m_id{static_cast<::std::int32_t>(0.0e0)};
    double m_bearing{0.0e0};
    double m_range{0.0e0};
};

} // namespace model

#endif // T_H
