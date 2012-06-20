#ifndef QUANTUMCHANNEL_H
#define QUANTUMCHANNEL_H

#include "../qbit.h"
#include <vector>

using namespace std;

class QuantumChannel
{
public:
    QuantumChannel();
    QBit* get_first();
    QBit* read_first();
    void add(QBit* item);

private:
    vector<QBit*> qbitQueue;
};

#endif // QUANTUMCHANNEL_H
