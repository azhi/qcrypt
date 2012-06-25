#include <QtCore>
#include <QtDeclarative>

#include <time.h>
#include <stdlib.h>

#include "connectioncontroller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDeclarativeView view;

    srand(time(NULL));
    ConnectionController* cc = new ConnectionController();
    cc->generateKey(100);
    view.rootContext()->setContextProperty("alice", cc->alice);
    view.setSource(QUrl::fromLocalFile("qml/qc_main_from/untitled.qml"));
    view.show();

    return app.exec();
}
