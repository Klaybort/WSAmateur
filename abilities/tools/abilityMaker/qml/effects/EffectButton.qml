import QtQuick 2.12
import QtQuick.Controls 2.12

Column {
    property int position

    signal editCondition(int pos)
    signal editEffect(int pos)

    spacing: 5

    Button {
        text: "Condition " + position
        onClicked: editCondition(position)
    }

    Button {
        text: "Effect " + position
        onClicked: editEffect(position)
    }
}
