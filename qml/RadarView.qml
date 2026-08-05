import QtQuick 2.15

Item {
    property var model

    property real radarSize: Math.min(parent.width, parent.height) * 0.95

    Image {
        source: "qrc:/assets/radar_grid.svg"
        width: radarSize
        height: radarSize
        anchors.centerIn: parent
    }

    Image {
        id: sweepLayer
        source: "qrc:/assets/radar_sweep.svg"
        width: radarSize
        height: radarSize
        anchors.centerIn: parent
        rotation: model ? model.sweepAngle : 0
        antialiasing: true
        smooth: true
    }

    Repeater {
        model: radarModel ? radarModel.targetList : []
        delegate: RadarBlipDelegate {
            targetData: modelData
            centerX: parent.width / 2
            centerY: parent.height / 2
            maxRadius: radarSize / 2
        }
    }
}