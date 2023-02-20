import QtQuick 2.0

BorderImage {
    property alias text: _buttonAdd.text
    signal clicked
    width: 763
    height: 300
    Text
    {
        id: _buttonAdd
        color: "black"
        anchors.centerIn: parent
    }
    MouseArea
    {
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
