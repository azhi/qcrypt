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
    eve = new Intercepter(qChannel, oChannel);
    eveActive = true;
    cout << "Successfully created bob, alice and eve!" << endl;
}

bool ConnectionController::generateKey(int keyLength)
{
    for( int i=0; i<keyLength; ++i)
    {
        alice->sendQBit(alice->generateRandomQBit());
        if (eveActive)
            eve->interceptQBit();
        bob->processQBit(bob->getQBit());
    }

    bob->sendTypeInfo(keyLength);
    if (eveActive)
        eve->interceptTypeInfo(keyLength);
    alice->getTypeInfo(keyLength);

    alice->sendCorrectIndexes();
    if (eveActive)
        eve->interceptCorrectIndexes();
    bob->getCorrectIndexes();

    alice->sendCheck(0, 18);
    if (eveActive)
        eve->interceptCheck();
    bool successfulGeneration = bob->getCheck();

    alice->calcActiveKey();
    bob->calcActiveKey();
    eve->calcActiveKey();

    if (successfulGeneration)
        cout << "Everything fine!" << endl;
    else
        cout << "Something went wrong :(" << endl;
    cout << "alice: " << alice->getActiveKey() << endl;
    cout << "bob: " << bob->getActiveKey() << endl;
    cout << "eve: " << eve->getActiveKey() << endl;

    return successfulGeneration;
}

void ConnectionController::sendText(string* msg)
{
}
