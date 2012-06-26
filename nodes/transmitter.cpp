#include "transmitter.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void Transmitter::sendQBit(QBit* qbit)
{
    qChannel->add(qbit);
}

void Transmitter::sendMsg(vector<int> msg)
{
    oChannel->add(msg);
}

QBit* Transmitter::generateRandomQBit()
{
    bool type = rand() % 2;
    bool val = rand() % 2;
    key.push_back( KeyDescriptor(type, val, 0) );
    return new QBit(type, val);
}

void Transmitter::getTypeInfo(int keyLength)
{
    for(int i=0; i<keyLength; ++i)
        rcverKey.push_back( KeyDescriptor(oChannel->get_first(), 0, 0) );
}

void Transmitter::sendCorrectIndexes()
{
    vector<int> correctIndexes;
    for(int i=0; i<rcverKey.size(); ++i)
        if ( key[i].polarization_type == rcverKey[i].polarization_type )
        {
            key[i].isActive = 1;
            correctIndexes.push_back(i);
        }
    sendMsg(correctIndexes);
}

void Transmitter::sendCheck(int startPos, int count)
{
    vector<int> checkMsg;
    checkMsg.push_back(startPos);
    checkMsg.push_back(count);
    for( int i = startPos; i < key.size() && count != 0; ++i)
        if ( key[i].isActive )
        {
            key[i].isActive = 0;
            checkMsg.push_back(key[i].bit);
            count--;
        }
    if ( count != 0 )
        checkMsg[1] -= count;
    sendMsg(checkMsg);
}

void Transmitter::sendText(string msg)
{
    vector<int> encodedMsg;
    for( int i=0; i < msg.size(); ++i)
        encodedMsg.push_back(msg[i] ^ activeKey[i % activeKey.size()]);
    sendMsg(encodedMsg);
}

void Transmitter::clearKey()
{
    key.clear();
    activeKey.clear();
    rcverKey.clear();
}
