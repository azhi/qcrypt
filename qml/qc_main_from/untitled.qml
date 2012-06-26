// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    width: 1000
    height: 400

    Rectangle {
        id: alice_descr
        x: 124
        y: 12
        width: 215
        height: 289
        color: "#ffffff"
        border.color: "#000000"

        Text {
            id: alice_label
            x: 94
            y: 6
            text: qsTr("Alice")
            font.pixelSize: 12
        }

        Image {
            id: alice_avatar
            x: 58
            y: 34
            width: 100
            height: 100
            source: "Pictures/alice.png"
        }

        Image {
            id: cur_al_polarization
            objectName: "alice_polarization"
            x: 88
            y: 139
            width: 40
            height: 40
            source: "Pictures/Polarizations/S-polariz.gif"
        }

        Text {
            id: key_al_label
            objectName: "alice_key"
            x: 15
            y: 231
            text: qsTr("Key: ")
            font.pixelSize: 12
        }

        Rectangle {
            id: text_border
            x: 9
            y: 256
            width: 86
            height: 20
            color: "#ffffff"
            border.color: "#000000"
        }

        TextInput {
            id: send_text_field
            x: 15
            y: 259
            width: 80
            height: 20
            text: qsTr("")
            font.pixelSize: 12
        }

        Rectangle {
            id: send_btn
            x: 121
            y: 256
            width: 80
            height: 20
            color: "#ffffff"
            border.color: "#000000"

            MouseArea {
                id: send_area
                x: 0
                y: 0
                width: 80
                height: 20
                onClicked: {
                    cc.sendText(send_text_field.text)
                }
            }

            Text {
                id: send_label
                x: 0
                y: 0
                width: 80
                height: 20
                text: qsTr("Send text")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
        }

        TextInput {
            id: key_al_field
            x: 49
            y: 228
            width: 152
            height: 20
            text: qsTr("")
            readOnly: true
            font.pixelSize: 12
        }

        Rectangle {
            id: generate_btn
            x: 50
            y: 199
            width: 116
            height: 20
            color: "#ffffff"
            border.color: "#000000"
            MouseArea {
                id: generate_area
                x: 0
                y: 0
                width: 116
                height: 20
                onClicked: { cc.generateKey(100) }
            }

            Text {
                id: generate_label
                x: 0
                y: 0
                width: 116
                height: 20
                text: qsTr("Generate key")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }



    }

    Rectangle {
        id: bob_descr
        x: 654
        y: 12
        width: 215
        height: 242
        color: "#ffffff"
        border.color: "#000000"
        Text {
            id: bob_label
            x: 97
            y: 8
            text: qsTr("Bob")
            font.pixelSize: 12
        }

        Image {
            id: bob_avatar
            x: 58
            y: 34
            width: 100
            height: 100
            source: "Pictures/bob.png"
        }

        Image {
            id: cur_bob_polarization
            objectName: "bob_polarization"
            x: 88
            y: 139
            width: 40
            height: 40
            source: "Pictures/Polarizations/D+polariz.gif"
        }

        Text {
            id: key_bob_label
            objectName: "bob_key"
            x: 15
            y: 188
            text: qsTr("Key: ")
            z: 1
            font.pixelSize: 12
        }

        TextInput {
            id: key_bob_field
            x: 49
            y: 185
            width: 152
            height: 20
            text: qsTr("")
            font.pixelSize: 12
            readOnly: true
        }

        TextEdit {
            id: text_bob_field
            objectName: "bob_text"
            x: 109
            y: 215
            width: 92
            height: 20
            text: qsTr("")
            font.pixelSize: 12
        }

        Text {
            id: text_bob_label
            x: 15
            y: 218
            text: qsTr("Receiving text:")
            font.pixelSize: 12
            z: 1
        }


    }

    Rectangle {
        id: eve_descr
        x: 393
        y: 101
        width: 215
        height: 273
        color: "#ffffff"
        border.color: "#000000"
        Text {
            id: eve_label
            x: 99
            y: 6
            text: qsTr("Eve")
            font.pixelSize: 12
        }

        Image {
            id: eve_avatar
            x: 58
            y: 34
            width: 100
            height: 100
            source: "Pictures/eve.png"
        }

        Text {
            id: key_eve_label
            objectName: "eve_key"
            x: 15
            y: 216
            text: qsTr("Key: ")
            font.pixelSize: 12
            z: 1
        }

        TextInput {
            id: key_bob_field1
            x: 49
            y: 214
            width: 152
            height: 20
            text: qsTr("")
            font.pixelSize: 12
            readOnly: true
        }

        Image {
            id: cur_eve_polarization
            objectName: "eve_polarization"
            x: 88
            y: 139
            width: 40
            height: 40
            source: "Pictures/Polarizations/D-polariz.gif"
        }

        TextEdit {
            id: text_eve_field
            objectName: "eve_text"
            x: 111
            y: 243
            width: 90
            height: 20
            text: qsTr("")
            font.pixelSize: 12
        }

        Text {
            id: text_eve_label
            x: 15
            y: 246
            text: qsTr("Intercept text:")
            font.pixelSize: 12
            z: 1
        }

        Rectangle {
            id: active_btn
            x: 50
            y: 185
            width: 116
            height: 20
            color: "#ffffff"
            border.color: "#000000"
            MouseArea {
                id: active_area
                x: 0
                y: 0
                width: 116
                height: 20
                onClicked: {
                    if (cc.isEveActive()) {
                        cc.setEveActive(false);
                        active_label.text = qsTr("Activate Eve");
                    }
                    else {
                        cc.setEveActive(true);
                        active_label.text = qsTr("Deactivate Eve");
                    }

                    text_eve_field.text = qsTr("");
                    key_eve_label.text = qsTr("Key: ");
                }
            }

            Text {
                id: active_label
                x: 0
                y: 0
                width: 116
                height: 20
                text: qsTr("Deactivate Eve")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }


    }
}
