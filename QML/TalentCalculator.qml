import QtQuick 2.0

Rectangle {
    color: root.darkGray
    height: width / 3 * 1.77 + 50
    width: parent.width

    Connections {
        target: warrior
        onTalentsUpdated: {
            leftTotalPoints.text = warrior.getTreePoints("LEFT")
            midTotalPoints.text = warrior.getTreePoints("MID")
            rightTotalPoints.text = warrior.getTreePoints("RIGHT")
        }
    }

    Row {
        height: width / 3 * 1.77
        width: parent.width - 1
        x: 1

        spacing: 1

        TalentTree {
            talentTreeImage: "Assets/warrior/warrior_arms.jpg"
            treePosition: "LEFT"
            y: 1
            height: parent.height - 2
            width: parent.width / 3 - 1
        }

        TalentTree {
            talentTreeImage: "Assets/warrior/warrior_fury.jpg"
            treePosition: "MID"
            y: 1
            height: parent.height - 2
            width: parent.width / 3 - 1
        }

        TalentTree {
            talentTreeImage: "Assets/warrior/warrior_protection.jpg"
            treePosition: "RIGHT"
            y: 1
            height: parent.height - 2
            width: parent.width / 3 - 1
        }
    }

    Rectangle {
        anchors {
            bottom: parent.bottom
            left: parent.left
            right: parent.right
        }
        height: 50
        color: "transparent"

        Row {
            anchors.fill: parent

            Text {
                id: leftTotalPoints
                height: parent.height
                width: parent.width / 3

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                color: root.gold

                font {
                    family: fontFamily
                    pointSize: 28
                }

                text:  warrior.getTreePoints("LEFT")
            }

            Text {
                id: midTotalPoints
                height: parent.height
                width: parent.width / 3

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                color: root.gold

                font {
                    family: fontFamily
                    pointSize: 28
                }

                text:  warrior.getTreePoints("MID")
            }

            Text {
                id: rightTotalPoints
                height: parent.height
                width: parent.width / 3

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                color: root.gold

                font {
                    family: fontFamily
                    pointSize: 28
                }

                text:  warrior.getTreePoints("RIGHT")
            }
        }
    }
}