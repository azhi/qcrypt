#include "receiver.h"
#include <stdlib.h>

QBit* Receiver::getQBit()
{
    return qChannel->get_first();
}

vector<int> Receiver::getMsg()
{
    vector<int> res;
    for( int tmp = oChannel->get_first(); tmp != -1; res.push_back(tmp), tmp = oChannel->get_first() );
    return res;
}

void Receiver::processQBit(QBit* qbit)
{
    bool type = rand() % 2;
    bool val = qbit->getValue(type);
    lastQBitInformation = type + val * 2;
    key.push_back( KeyDescriptor(type, val, 0) );
}

void Receiver::sendTypeInfo(int keyLength)
{
    for(int i=0; i<keyLength; ++i)
        oChannel->add(key[i].polarization_type);
}

void Receiver::getCorrectIndexes()
{
    vector<int> correctIndexes = getMsg();
    vector<int>::iterator curCI = correctIndexes.begin();
    while ( curCI != correctIndexes.end() )
    {
        key[*curCI].isActive = 1;
        ++curCI;
    }
}

string Receiver::getCheck(bool* res)
{
    string returningMsg; //returning check message for system log
    *res = true;
    vector<int> checkMsg = getMsg();
    int startPos = checkMsg[0]; int count = checkMsg[1];
    for (int i = startPos, j=2; i < key.size() && count != 0; ++i)
        if ( key[i].isActive )
        {
            key[i].isActive = 0;
            *res &= key[i].bit == checkMsg[j++];
            returningMsg.append(key[i].bit?"1":"0");
            count--;
        }
    return returningMsg;
}

string Receiver::getText()
{
    vector<int> encodedMsg = getMsg();
    string decodedMsg;
    for( int i=0; i < encodedMsg.size(); ++i)
        decodedMsg.push_back(encodedMsg[i] ^ activeKey[i % activeKey.size()]);
    return decodedMsg;
}
