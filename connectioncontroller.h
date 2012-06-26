#ifndef CONNECTIONCONTROLLER_H
#define CONNECTIONCONTROLLER_H

#include "nodes/receiver.h"
#include "nodes/transmitter.h"
#include "nodes/intercepter.h"
#include "uicontroller.h"

class ConnectionController : public QObject
{
    Q_OBJECT
public:
    ConnectionController(UiController* uicontr);

    Q_INVOKABLE bool generateKey(int keyLength);
    Q_INVOKABLE void sendText(QString msg);
    Q_INVOKABLE bool isEveActive();
    Q_INVOKABLE void setEveActive(bool active);
    Transmitter* getTransmitterInstance() { return alice; }
    Receiver* getReceiverInstance() { return bob; }
    Intercepter* getIntercepterInstance() { return eve; }

    bool eveActive;

private:
    UiController* uicontr;

    Transmitter* alice;
    Receiver* bob;
    Intercepter* eve;
};

#endif // CONNECTIONCONTROLLER_H
