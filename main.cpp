#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "src/model/RadarModel.h"
#include "src/model/Target.h"
#include "src/controller/RadarController.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    
    RadarModel model;

    
    
    model.addTarget(new Target(1,  45.0, 0.6));
    
    model.addTarget(new Target(2, 135.0, 0.4));
    
    model.addTarget(new Target(3, 225.0, 0.5));
    
    model.addTarget(new Target(4, 315.0, 0.2));

    
    RadarController controller;
    controller.setModel(&model);

    
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("radarModel", &model);

    
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    
    controller.start();

    return app.exec();
}