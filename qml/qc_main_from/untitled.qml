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
        height: 242
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
            x: 88
            y: 139
            width: 40
            height: 40
            source: "Pictures/Polarizations/V_pol.xcf"
        }

        Text {
            id: key_al_label
            x: 15
            y: 188
            text: qsTr("Key:")
            font.pixelSize: 12
        }

        Rectangle {
            id: text_border
            x: 9
            y: 213
            width: 86
            height: 20
            color: "#ffffff"
            border.color: "#000000"
        }

        TextInput {
            id: send_text_field
            x: 15
            y: 216
            width: 80
            height: 20
            text: qsTr("")
            font.pixelSize: 12
        }

        Rectangle {
            id: send_btn
            x: 121
            y: 213
            width: 80
            height: 20
            color: "#ffffff"

            MouseArea {
                id: send_area
                x: 0
                y: 0
                width: 80
                height: 20
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
            y: 185
            width: 152
            height: 20
            text: qsTr("")
            readOnly: true
            font.pixelSize: 12
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
            x: 88
            y: 139
            width: 40
            height: 40
            source: "Pictures/Polarizations/V_pol.xcf"
        }

        Text {
            id: key_bob_label
            x: 15
            y: 188
            text: qsTr("Key:")
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
        y: 123
        width: 215
        height: 242
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
            x: 15
            y: 189
            text: qsTr("Key:")
            font.pixelSize: 12
            z: 1
        }

        TextInput {
            id: key_bob_field1
            x: 49
            y: 187
            width: 152
            height: 20
            text: qsTr("")
            font.pixelSize: 12
            readOnly: true
        }

        Image {
            id: cur_eve_polarization
            x: 88
            y: 139
            width: 40
            height: 40
            source: "Pictures/Polarizations/V_pol.xcf"
        }

        TextEdit {
            id: text_eve_field
            x: 111
            y: 216
            width: 90
            height: 20
            text: qsTr("")
            font.pixelSize: 12
        }

        Text {
            id: text_eve_label
            x: 15
            y: 219
            text: qsTr("Intersept text:")
            font.pixelSize: 12
            z: 1
        }


    }
}
