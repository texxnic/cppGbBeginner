import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.3

Window {
    width: 640
    height: 480
    visible: true
    color: "#4e4e4e"
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 220
        y: 140
        radius: 0
        width: 200
        height: 200
        color: "#ffffff"
        MouseArea {
                          anchors.fill: parent
                          acceptedButtons: Qt.LeftButton | Qt.RightButton

                          onClicked: {
                              if(mouse.button & Qt.RightButton) {
                                    rotationAnimation.running = true;
                              } else {
                                 rectangle.color = "#" + Math.floor(Math.random()*16777215).toString(16);
                              }
                          }
                          onDoubleClicked: {
                              rectangle.radius = 200;

                          }

                      }

            PropertyAnimation {
                property: "rotation";
                 target: rectangle;
                id: rotationAnimation;
                to: 360;
                duration: 1000;
        }
    }


}


