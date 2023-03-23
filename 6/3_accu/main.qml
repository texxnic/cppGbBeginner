import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

            Button{
                text: "Загрузить погоду"
                onClicked: {
                    var xhr = new XMLHttpRequest();

                            xhr.onreadystatechange = function() {
                                if (xhr.readyState === XMLHttpRequest.DONE) {
                                    if (xhr.status === 200) {
                                        weatherDescription.text = JSON.parse(xhr.responseText);

                                    } else {
                                        console.log("Error fetching data");
                                    }
                                }
                            }
                            xhr.open("GET", "https://api.gismeteo.net/v2/search/cities/?lang=en&query=szczecin");
                                        xhr.setRequestHeader("X-Gismeteo-Token", "56b30cb255.3443075");
                            xhr.send();
                }
            }
            Text{
                id:weatherDescription
                color: "black"
                height: parent.height -30
                width: parent.width
                wrapMode: Text.WordWrap
            }



}
