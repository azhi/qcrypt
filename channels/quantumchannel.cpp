#include "quantumchannel.h"
#include <string.h>

QuantumChannel::QuantumChannel()
{
    qbitQueue.clear();
}

QBit* QuantumChannel::read_first()
{
    return qbitQueue.front();
}

QBit* QuantumChannel::get_first()
{
    QBit* res = qbitQueue.front();
    if ( res != NULL )
        qbitQueue.erase(qbitQueue.begin());
    return res;
}

void QuantumChannel::add(QBit* item)
{
    qbitQueue.push_back(item);
}
