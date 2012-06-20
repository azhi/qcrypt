#include "transmitter.h"
#include <stdlib.h>

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
    bool type = rand()%2;
    bool val = rand()%2;
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
