#include "connectioncontroller.h"
#include <iostream>

using namespace std;

ConnectionController::ConnectionController()
{
    QuantumChannel* qChannel = new QuantumChannel();
    OpenChannel* oChannel = new OpenChannel();
    cout << "Successfully created 2 channels!" << endl;
    alice = new Transmitter(qChannel, oChannel);
    bob = new Receiver(qChannel, oChannel);
    cout << "Successfully created bob and alice!" << endl;
}

void ConnectionController::generateKey(int keyLength)
{
    for( int i=0; i<keyLength; ++i)
    {
        alice->sendQBit(alice->generateRandomQBit());
        bob->processQBit(bob->getQBit());
    }
    bob->sendTypeInfo(keyLength);
    alice->getTypeInfo(keyLength);
    alice->sendCorrectIndexes();
    bob->getCorrectIndexes();

    alice->calcActiveKey();
    bob->calcActiveKey();
    cout << "alice: " << alice->activeKey << endl;
    cout << "bob: " << bob->activeKey << endl;
}

void ConnectionController::sendText(string* msg)
{
}
