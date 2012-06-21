#ifndef CONNECTIONCONTROLLER_H
#define CONNECTIONCONTROLLER_H

#include <nodes/receiver.h>
#include <nodes/transmitter.h>
#include <nodes/intercepter.h>

class ConnectionController
{
public:
    ConnectionController();

    bool generateKey(int keyLength);
    void sendText(string* msg);

    bool eveActive;

private:
    Transmitter* alice;
    Receiver* bob;
    Intercepter* eve;
};

#endif // CONNECTIONCONTROLLER_H
