#ifndef Rc_H
#define Rc_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
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
    RadarModel *m_model = nullptr;
    QTimer m_timer;
    QElapsedTimer m_elapsed;
    double m_lastTime = 0.0;
    double m_rpm = 24.0; // 24 RPM = standard marine radar
};

#endif 