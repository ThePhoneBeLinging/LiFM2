import QtQuick 6.5
import QtQuick.Controls 6.5

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: "Hello World"

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: Mail {

        }
    }

    function pushToStack(item) {
        stackView.push(item);
    }

    function popFromStack() {
        stackView.pop();
    }
}