#ifndef CONNECTIONCONTROLLER_H
#define CONNECTIONCONTROLLER_H

#include <nodes/receiver.h>
#include <nodes/transmitter.h>

class ConnectionController
{
public:
    ConnectionController();

    void generateKey(int keyLength);
    void sendText(string* msg);

private:
    Transmitter* alice;
    Receiver* bob;
};

#endif // CONNECTIONCONTROLLER_H
