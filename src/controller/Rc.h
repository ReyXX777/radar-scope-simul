#ifndef RC_H
#define RC_H

#include <cstdint>
#include <QElapsedTimer>
#include <QObject>
#include <QTimer>
#include "model/Rm.h"

namespace model {
class RadarModel;
}

namespace controller {

class RadarController : public QObject {
    Q_OBJECT
public:
    explicit RadarController(::QObject *l_parent = nullptr);
    void setModel(::model::RadarModel *l_model);
    void start();

private slots:
    void onTick();

private:
    ::model::RadarModel *m_model{nullptr};
    ::QTimer m_timer{};
    ::QElapsedTimer m_elapsed{};
    double m_lastTime{0.0e0};
    double m_rpm{2.4e1};
};

} // namespace controller

#endif // RC_H
