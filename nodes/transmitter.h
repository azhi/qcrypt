#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "node.h"
#include "../qbit.h"

class Transmitter : public Node
{
public:
    Transmitter(QuantumChannel* qChannel, OpenChannel* oChannel) : Node(qChannel, oChannel) {};
    void sendQBit(QBit* qbit);
    void sendMsg(vector<int> msg);
    QBit* generateRandomQBit();

    void getTypeInfo(int keyLength);
    void sendCorrectIndexes();

private:
    vector<KeyDescriptor> rcverKey;
};

#endif // TRANSMITTER_H
