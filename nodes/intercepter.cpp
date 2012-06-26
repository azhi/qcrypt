#include "intercepter.h"
#include <stdlib.h>

void Intercepter::interceptQBit()
{
    QBit* qbit = qChannel->get_first();
    bool type = rand() % 2;
    bool val = qbit->getValue(type);
    lastQBitInformation = type + val * 2;
    key.push_back( KeyDescriptor(type, val, 0) );
    qChannel->add( new QBit(type,val) );
}

vector<int> Intercepter::interceptMsg()
{
    vector<int> res;
    for( int tmp = oChannel->get_first(); tmp != -1; res.push_back(tmp), tmp = oChannel->get_first() );
    oChannel->add(res);
    return res;
}

void Intercepter::interceptTypeInfo(int keyLength)
{
    vector<int> typeInfo = interceptMsg();
    for(int i=0; i<keyLength; ++i)
        rcverKey.push_back( KeyDescriptor(typeInfo[i], 0, 0) );
}

void Intercepter::interceptCorrectIndexes()
{
    vector<int> correctIndexes = interceptMsg();
    vector<int>::iterator curCI = correctIndexes.begin();
    while ( curCI != correctIndexes.end() )
    {
        key[*curCI].isActive = 1;
        ++curCI;
    }
}

void Intercepter::interceptCheck()
{
    vector<int> checkMsg = interceptMsg();
    int startPos = checkMsg[0]; int count = checkMsg[1];
    for (int i = startPos; i < key.size() && count != 0; ++i)
        if ( key[i].isActive )
        {
            key[i].isActive = 0;
            count--;
        }
}

string Intercepter::interceptText()
{
    vector<int> encodedMsg = interceptMsg();
    string decodedMsg;
    for( int i=0; i < encodedMsg.size(); ++i)
        decodedMsg.push_back(encodedMsg[i] ^ activeKey[i % activeKey.size()]);
    return decodedMsg;
}

void Intercepter::clearKey()
{
    key.clear();
    activeKey.clear();
    rcverKey.clear();
}
