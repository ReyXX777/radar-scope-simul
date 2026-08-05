import QtQuick 2.15

Item {
    id: root
    property var targetData
    property real centerX
    property real centerY
    property real maxRadius

    width: 48
    height: 48

    // Trigonometric positioning per Master Architecture Guide
    x: centerX + (targetData.range * maxRadius) * Math.sin(targetData.bearing * Math.PI / 180) - width / 2
    y: centerY - (targetData.range * maxRadius) * Math.cos(targetData.bearing * Math.PI / 180) - height / 2

    Image {
        id: blipImage
        source: "qrc:/assets/radar_blip.svg"
        anchors.fill: parent
        opacity: 0.0
        antialiasing: true
    }

    // QML-driven fade animation triggered by C++ ping signal
    NumberAnimation {
        id: fadeAnim
        target: blipImage
        property: "opacity"
        from: 1.0
        to: 0.0
        duration: 2000
        easing.type: Easing.OutQuad
    }

    Connections {
        target: radarModel
        function onTargetPing(pingedId) {
            if (pingedId === targetData.id) {
                fadeAnim.restart()
            }
        }
    }
}