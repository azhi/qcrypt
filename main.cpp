#include <QtCore>
#include <QtDeclarative>

#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "connectioncontroller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDeclarativeView view;

    view.setSource(QUrl("qrc:/qml/qc_main_from/untitled.qml"));

    srand(time(NULL));
    UiController* uicontr = new UiController(view.rootObject());
    ConnectionController* cc = new ConnectionController(uicontr);

    view.rootContext()->setContextProperty("cc", cc);
    view.rootContext()->setContextProperty("alice", cc->getTransmitterInstance());
    view.rootContext()->setContextProperty("bob", cc->getReceiverInstance());
    view.rootContext()->setContextProperty("eve", cc->getIntercepterInstance());

    cc->generateKey(100);
    view.show();

    return app.exec();
}
