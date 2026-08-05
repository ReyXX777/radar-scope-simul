import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 800
    height: 800
    title: "Radar Scope Simulation"
    color: "#050f05"

    RadarView {
        anchors.fill: parent
        model: radarModel
    }
}