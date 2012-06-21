#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <time.h>
#include <stdlib.h>
#include "connectioncontroller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/qcrypt/main.qml"));
    viewer.showExpanded();

    srand(time(NULL));
    ConnectionController* cc = new ConnectionController();
    cc->generateKey(100);

    return app->exec();
}
