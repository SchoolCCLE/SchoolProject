import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1





Rectangle {

    id:root;

    signal buttonLogIn(string nickName, string password);

    visible: true
    width: 800
    height: 600
    //color:"cyan";



    ColumnLayout
    {
        anchors.fill: root;
        anchors.margins: 20;
        id: columnRoot;

        spacing: 5;

        RowLayout
        {
            id:rowLay1;
            Layout.fillWidth:  true;
            height:50;

            Label
            {
                id:labelNick;
                text: "NickName";
                height: 25;
                width: 25;
            }

        }


        RowLayout
        {
            id:rowLay2;
            Layout.fillWidth:  true;
            height: 50;
            TextField
            {
                id: tNick;
                //anchors.fill: parent;
                //Layout.fillHeight: true;
                width: 100;
                height:50;

                //color:"grey";

            }

        }
        RowLayout
        {
            id:rowLay3;
            //Layout.fillWidth:  true;
            height:50;
            Label
            {
                id:labelPass;
                text: "Password: ";
                height: 25;
                width: 25;
            }

        }
        RowLayout
        {
            id:rowLay4;
            Layout.fillWidth:  true;
            height:50;

            TextField
            {
                id: tPass;
                width: 100;
                height:50;

            }

        }
        RowLayout
        {
            id:rowLay5;

            //            Layout.fillWidth:  true;
            Button
            {
                text:"Log In";

                onClicked:
                {
                    root.buttonLogIn(tNick.text.toString(),tPass.text.toString());
                }
            }

        }
    }

}
