import QtQuick
import QtQuick.Controls
import "../db/dbHelpers.js" as DbHelpers
import QtQuick.Window 2.15
import Qt.labs.qmlmodels 1.0
import QtQuick.LocalStorage 2.12





Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("DB Example")
    property int cellHorizontalSpacing: 10
    property var db
    Component.onCompleted: {
        DbHelpers.dbList.forEach((dbName)=>{
                                     let db = LocalStorage.openDatabaseSync("DBExample" + dbName, "1.0", "Пример локальной базы данных", 1000);


                                     try {
                                         db.transaction(DbHelpers.createSimpleTable);
                                         db.transaction((tx) => {
                                                            DbHelpers.addContact(tx, "Иванов", "Иван", "ivanoviv2182@mail.ru",
                                                                                 "+7(988)37333112")
                                                            DbHelpers.addContact(tx, "Заварнов", "Владимир", "zavlad@mail.ru",
                                                                                 "+7(977)98373331")
                                                            DbHelpers.addContact(tx, "Говорун", "Максим", "landlord2000@mail.ru",
                                                                                 "+7(977)3311111")
                                                        })
                                     } catch (err) {
                                         console.log("Error creating or updating table in database: " + err)

                                     }
                                 })

    }

    function renderData(){
        db = LocalStorage.openDatabaseSync("DBExample" + dbSelected.currentValue, "1.0", "Пример локальной базы данных", 1000)
        try {

            db.transaction((tx) => { DbHelpers.readContacts(tx, table.model) })
        } catch (err) {
            console.log("Error creating or updating table in database: " + err)
        }
    }

    TableModel {
        id: tableModel
        TableModelColumn { display: "id" }
        TableModelColumn { display: "first_name" }
        TableModelColumn { display: "last_name" }
        TableModelColumn { display: "email" }
        TableModelColumn { display: "phone" }
        rows: []
    }
    TableView {
        id: table
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        model: tableModel
        delegate: Rectangle {
            implicitWidth: Math.max(100, cellHorizontalSpacing + innerText.width + cellHorizontalSpacing)
            implicitHeight: 50
            border.width: 1
            Text {
                id: innerText
                text: display
                anchors.centerIn: parent
            }
        }
    }
    ComboBox {
        editable: true
        id:dbSelected
        model: DbHelpers.dbList
        anchors.right: parent.right
        onActivated: {
            console.log(index)
            renderData();
        }
        indicator: Text {
            text: "\u25BE" // Unicode character for downward-pointing triangle
            font.pixelSize: 30
            transform: Rotation {
                id: chevronRotation
                origin.y: parent.right
                angle: dbSelected.down ? 180 : 0
            }
        }
    }

    Dialog {
        id: dialog
        anchors.centerIn: parent
        title: "Add person"
        standardButtons: Dialog.Ok | Dialog.Cancel
        background: Rectangle {
            color: "white"
            radius: 10
            border.color: "black"
            border.width: 1
        }
        Column {
            anchors.fill: parent
            spacing: 5
            TextField {
                id: firstName
                placeholderText: "Имя"
            }
            TextField {
                id: lastName
                placeholderText: "Фамилия"
            }
            TextField {
                id: email
                placeholderText: "E-mail"
            }
            TextField {
                id: phone
                placeholderText: "Номер телефона"
            }
        }
        onAccepted: {
            try {
                db.transaction((tx) => {
                                   var resObj = DbHelpers.addContact(tx, firstName.text,
                                                                     lastName.text,
                                                                     email.text,
                                                                     phone.text);
                                   if (resObj.rowsAffected !== 0) {
                                       tableModel.appendRow({
                                                                id: resObj.insertId,
                                                                first_name: firstName.text,
                                                                last_name: lastName.text,
                                                                email: email.text,
                                                                phone: phone.text
                                                            })
                                   }
                               })
            } catch (err) {
                console.log("Error creating or updating table in database: " + err)
            }
        }
    }
    Button {
        id: button
        text: "Добавить человека"
        width: parent.width
        height: 50
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        onClicked: dialog.open()
    }
}
