import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.3

Window {
    width: 640
    height: 480
    visible: true
    color: "#4e4e4e"
    title: qsTr("Hello World")
    property var idMap: ({ myName:myName, myAge:myAge, myHobby:myHobby, myCity:myCity, myAbout:myAbout, myEducation:myEducation, forEducation:forEducation })

    Column {
        id: column
        width: 200
        height: 400

        Row {
            id: row1
            width: 200
            height: 400

            Column {
                id: column1
                width: 200
                height: 314


                Text {
                    id: text0
                    text: qsTr("О себе")
                    font.pixelSize: 12
                    bottomPadding: 20
                }

                TextField {
                    id: myName
                    color: "#d8000000"
                    placeholderText: qsTr("Имя")
                }

                TextField {
                    id: myAge
                    placeholderText: qsTr("возраст")
                }

                Text {
                    id: text2
                    text: qsTr("Пол")
                    font.pixelSize: 12
                }

                Row {
                    id: row
                    width: 100
                    height: 20
                    anchors.left: parent.left
                    anchors.leftMargin: 0

                    RadioButton {
                        id: mySexM
                        text: qsTr("М")
                        checked: true
                    }


                    RadioButton {
                        id: mySexW
                        text: qsTr("Ж")
                    }

                }

                TextField {
                    id: myHobby
                    placeholderText: qsTr("хобби")
                }

                TextField {
                    id: myCity
                    placeholderText: qsTr("город")
                }

                TextField {
                    id: myAbout
                    layer.textureSize.height: 5
                    layer.textureSize.width: 5
                    placeholderText: qsTr("о мне")
                }

                TextField {
                    id: myEducation
                    layer.textureSize.width: 5
                    layer.textureSize.height: 5
                    placeholderText: qsTr("образрвание")
                }

            }

            Column {
                id: column2
                width: 200
                height: 314

                Text {
                    id: text9
                    text: qsTr("Параметры поиска")
                    font.pixelSize: 12
                    bottomPadding: 20
                }



                Text {
                    id: ageRangeTitle
                    text: qsTr("возрастные границы")
                    font.pixelSize: 12
                }

                RangeSlider {
                    id: forRange
                    snapMode: RangeSlider.SnapAlways
                    touchDragThreshold: 0
                    stepSize: 1
                    to: 99
                    from: 18
                    second.value: 50
                    first.value: 25
                }

                Text {
                    id: forRangeValue
                    text: forRange.first.value + " - " + forRange.second.value
                    font.pixelSize: 12
                }


                TextField {
                    id: forEducation
                    layer.textureSize.width: 5
                    layer.textureSize.height: 5
                    placeholderText: qsTr("уровень образования")
                }

                Text {
                    id: sexTitle
                    text: qsTr("Пол")
                    font.pixelSize: 12
                }
                Row {
                    id: row2
                    width: 100
                    height: 20
                    anchors.left: parent.left
                    anchors.leftMargin: 0

                    RadioButton {
                        id: forSexM
                        text: qsTr("М")
                        checked: true
                    }

                    RadioButton {
                        id: forSexW
                        text: qsTr("Ж")
                    }
                }
            }

        }

        Row {
            id: row3
            width: 200
            height: 400

            Button {
                id: button
                width: 138
                height: 43
                text: qsTr("Регистрация")
                icon.color: "#ffffff"
                function handleClick(){
                   const myFieldsIds = ["myName","myAge", 'myHobby', "myCity", "myAbout", "myEducation"];
                    const myRadioSelected = mySexM.checked ? mySexM : mySexW;
                    const forFieldsIds = ["forEducation"];
                    const forRadioSelected = forSexM.checked ? forSexM : forSexW;

                    function printValues(preText, fieldsList, sexRadio){
                        console.log(preText);
                        fieldsList.forEach(id => {
                            let obj = idMap[id];
                                              if(obj){
                                                  console.log(obj.placeholderText + ": " +obj.text)
                                              }
                                          });
                        console.log("Пол: " + sexRadio.text);
                    }

                    printValues("О мне↓", myFieldsIds, myRadioSelected);
                    printValues("Параметры поиска↓", forFieldsIds, forRadioSelected);
                    console.log("Возраст: " + forRangeValue.text)

                }
                onClicked: handleClick()
            }


        }
    }
}


