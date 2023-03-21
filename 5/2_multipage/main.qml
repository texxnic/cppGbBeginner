import QtQuick 2.0
import QtQuick.Controls 2.3

ApplicationWindow {
    id: appWindow
    visible: true
    width: 640
    height: 480
    title: "My Application"
    color: "black"
    Component.onCompleted: {
        loader.sourceComponent = loginPage
    }

    Component {
        id: loginPage

        Item {
            id: loginPageItem
            width: appWindow.width
            height: appWindow.height

            Column {
                spacing: 10
                anchors.centerIn: parent

                TextField {
                    id: usernameField
                    placeholderText: "Username"
                    font.pixelSize: 18
                    width: 200
                }

                TextField {
                    id: passwordField
                    placeholderText: "Password"
                    font.pixelSize: 18
                    width: 200
                    echoMode: TextInput.Password
                }

                Button {
                    text: "Log In"
                    font.pixelSize: 18
                    width: 100
                    onClicked: {
                        if (usernameField.text === "user" && passwordField.text === "password") {
                            loader.sourceComponent = appPage1
                        } else {
                            errorMessage.visible = true
                        }
                    }
                }

                Text {
                    id: errorMessage
                    text: "Incorrect username or password"
                    font.pixelSize: 14
                    color: "red"
                    visible: false
                }
            }
        }
    }
    Component {
              id: appPage1

              Rectangle {
                  width: parent.width
                  height: parent.height
                  color: "green"

                  Text {
                      text: "page1"
                      font.pixelSize: 24
                      anchors.centerIn: parent
                  }

                  Button {
                      text: "logout"
                      font.pixelSize: 18
                      width: 100
                      anchors.bottom: parent.bottom
                      anchors.right: parent.right
                      onClicked: {
                          loader.sourceComponent = loginPage
                      }
                  }
              }
    }
    Loader {
    id: loader
    }
}
