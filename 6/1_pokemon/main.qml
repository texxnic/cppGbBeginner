import QtQuick
import QtQuick.Controls

Window {
    width: 1000
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "lightgray"
    Component.onCompleted:{
        var xhr = new XMLHttpRequest();
                xhr.onreadystatechange = function() {
                    if (xhr.readyState === XMLHttpRequest.DONE) {
                        if (xhr.status === 200) {
                            let data = JSON.parse(xhr.responseText);
                            console.log("Data fetched successfully", xhr.responseText);
                            data?.results?.forEach(({name, url}, i) =>{
                                                   myModel.append({name, url}); console.log(i)} );
                        } else {
                            console.log("Error fetching data");
                        }
                    }
                }
                xhr.open("GET", "https://pokeapi.co/api/v2/pokemon/");
                xhr.send();
    }

    ListModel {
        id: myModel

    }
    Row{
        width: parent.width
        height: parent.height
        ListView {
            model: myModel
            height: parent.height
            width: parent.width / 2
            delegate: Text {
                text: "Name: " + model.name + ", ID: " + model.url
                MouseArea {
                                   anchors.fill: parent
                                   onClicked: {
                                       var xhr = new XMLHttpRequest();
                                       xhr.onreadystatechange = function() {
                                           if (xhr.readyState === XMLHttpRequest.DONE) {
                                               if (xhr.status === 200) {
                                                   pokemonDescription.text = xhr.responseText;
                                               } else {
                                                   console.log("Error fetching data");
                                               }
                                           }
                                       }
                                       xhr.open("GET", model.url);
                                       xhr.send();
                                   }
                               }
            }
        }
        Text{
        id:pokemonDescription
        color: "black"
        height: parent.height
        width: parent.width / 2
        wrapMode: Text.WordWrap
        }
    }

}
