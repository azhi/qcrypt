#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include "node.h"

class Transmitter : public Node
{
public:
    Transmitter(QuantumChannel* qChannel, OpenChannel* oChannel) : Node(qChannel, oChannel) {};
    void sendQBit(QBit* qbit);
    void sendMsg(vector<int> msg);
    QBit* generateRandomQBit();

    void getTypeInfo(int keyLength);
    void sendCorrectIndexes();

    void sendCheck(int startPos, int count);

private:
    vector<KeyDescriptor> rcverKey;
};

#endif // TRANSMITTER_H
