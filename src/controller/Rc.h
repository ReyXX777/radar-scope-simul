#ifndef RC_H
#define RC_H

#include <cstdint>
#include <QElapsedTimer>
#include <QObject>
#include <QTimer>
#include "RadarModel.h"

class RadarController : public QObject {
    Q_OBJECT
public:
    explicit RadarController(QObject *parent = nullptr);
    void setModel(RadarModel *model);
    void start();

private slots:
    void onTick();

private:
    RadarModel *m_model{nullptr};
    QTimer m_timer{};
    QElapsedTimer m_elapsed{};
    double m_lastTime{0.0};
    double m_rpm{24.0};
};

#endif
