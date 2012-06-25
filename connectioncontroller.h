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
// FIXME: write getters for nodes and make this fields private back
//private:
    Transmitter* alice;
    Receiver* bob;
    Intercepter* eve;
};

#endif // CONNECTIONCONTROLLER_H
