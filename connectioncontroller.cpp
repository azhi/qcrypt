#include "connectioncontroller.h"
#include <iostream>

using namespace std;

ConnectionController::ConnectionController(UiController* uicontr) : uicontr(uicontr)
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

bool ConnectionController::isEveActive()
{
    return eveActive;
}

void ConnectionController::setEveActive(bool active)
{
    eveActive = active;
}

bool ConnectionController::generateKey(int keyLength)
{
    alice->clearKey(); bob->clearKey(); eve->clearKey();
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

    string keyMsg = "Key: " + alice->getActiveKey();
    uicontr->setProperty("alice_key", "text", keyMsg.c_str());
    keyMsg = "Key: " + bob->getActiveKey();
    uicontr->setProperty("bob_key", "text", keyMsg.c_str());
    keyMsg = "Key: " + eve->getActiveKey();
    uicontr->setProperty("eve_key", "text", keyMsg.c_str());

    return successfulGeneration;
}

void ConnectionController::sendText(QString msg)
{
    string eveText, bobText;
    alice->sendText(msg.toStdString());
    if (eveActive)
        eveText = eve->interceptText();
    bobText = bob->getText();

    uicontr->setProperty("eve_text", "text", eveText.c_str());
    uicontr->setProperty("bob_text", "text", bobText.c_str());
}
