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
    uicontr->clearLog();
    uicontr->writeToLog("Beginnig to generate the key");
    static const QUrl POLARIZATIONS[4] = {
        QUrl("qrc:/qml/qc_main_from/Pictures/Polarizations/S-polariz.gif"),
        QUrl("qrc:/qml/qc_main_from/Pictures/Polarizations/D-polariz.gif"),
        QUrl("qrc:/qml/qc_main_from/Pictures/Polarizations/S+polariz.gif"),
        QUrl("qrc:/qml/qc_main_from/Pictures/Polarizations/D+polariz.gif")
    };
    alice->clearKey(); bob->clearKey(); eve->clearKey();
    for( int i=0; i<keyLength; ++i)
    {
        alice->sendQBit(alice->generateRandomQBit());
        uicontr->refreshForm();
        if (eveActive)
        {
            eve->interceptQBit();
            uicontr->refreshForm();
        }
        bob->processQBit(bob->getQBit());
        if (i%5 == 1)
        {
          uicontr->refreshForm();
          uicontr->setProperty("alice_polarization", "source",
                               POLARIZATIONS[alice->getLastQBitInfo()].toString().toStdString().c_str());
          if (eveActive)
            uicontr->setProperty("eve_polarization", "source",
                                 POLARIZATIONS[eve->getLastQBitInfo()].toString().toStdString().c_str());
          uicontr->setProperty("bob_polarization", "source",
                               POLARIZATIONS[bob->getLastQBitInfo()].toString().toStdString().c_str());
          usleep(400000);
        }
    }

    uicontr->writeToLog("Sending information about bob filtering");
    bob->sendTypeInfo(keyLength);
    if (eveActive)
        eve->interceptTypeInfo(keyLength);
    alice->getTypeInfo(keyLength);

    uicontr->writeToLog("Sending information about correct bob quesses");
    int count = alice->sendCorrectIndexes();
    char* msg = (char*) malloc(sizeof(char)*500);
    sprintf(msg, "bob quessed rigth %d out of %d QBits", count, keyLength);
    uicontr->writeToLog(msg);
    if (eveActive)
        eve->interceptCorrectIndexes();
    bob->getCorrectIndexes();

    uicontr->writeToLog("Perform partial key checking");
    int checkLength = keyLength/5;
    int beginPos = random() % (keyLength - checkLength - 1);
    string aliceChKey = alice->sendCheck(beginPos, checkLength);
    sprintf(msg, "Alice's part of the key: %s", aliceChKey.c_str());
    uicontr->writeToLog(msg);
    if (eveActive)
        eve->interceptCheck();
    bool successfulGeneration;
    string bobChKey = bob->getCheck(&successfulGeneration);
    sprintf(msg, "Bob's part of the key:   %s", bobChKey.c_str());
    uicontr->writeToLog(msg);

    alice->calcActiveKey();
    bob->calcActiveKey();
    eve->calcActiveKey();

    if (successfulGeneration)
        uicontr->writeToLog("Everything is fine!");
    else
        uicontr->writeToLog("Something went wrong");

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
