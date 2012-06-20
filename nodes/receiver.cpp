#include "receiver.h"
#include <stdlib.h>
#include <iostream>

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
    bool type = rand()%2;
    bool val = qbit->getValue(type);
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
