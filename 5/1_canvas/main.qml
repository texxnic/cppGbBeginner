import QtQuick
import QtQuick.Window
import QtQuick.Controls
import "../CanvasJs.js" as CanvasJs

Window {
    width: 1000
    height: 1000
    visible: true
    title: qsTr("Hello World")
    ComboBox {
        id: variatCombobox
        width: 200
        model: CanvasJs.shapeNames
        onActivated: {
            canvas.requestPaint()
        }
    }
    Rectangle {
        id: rectangle
        width: parent.width
        height: parent.height - 40
        anchors.bottom: parent.bottom
            Canvas {
                id: canvas
                width: parent.height
                height: parent.height
                antialiasing: true
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                onPaint: {
                    var ctx = getContext("2d");
                    ctx.clearRect(0, 0, width, height);
                    ctx.beginPath();
                    let [firstPoint, ...points] = CanvasJs.getCoordinatesByIndex(variatCombobox.currentIndex);
                    ctx.moveTo(firstPoint.x, firstPoint.y);
                    points.forEach(point=>ctx.lineTo(point.x,point.y));
                    ctx.closePath();
                    ctx.lineWidth = 15;
                    ctx.stroke();

                }
            }
        }
}
