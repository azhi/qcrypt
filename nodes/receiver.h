#ifndef RECEIVER_H
#define RECEIVER_H

#include "node.h"

class Receiver : public Node
{
public:
    Receiver(QuantumChannel* qChannel, OpenChannel* oChannel) : Node(qChannel, oChannel) {};
    QBit* getQBit();
    vector<int> getMsg();
    void processQBit(QBit* qbit);

    void sendTypeInfo(int keyLength);
    void getCorrectIndexes();
    string getCheck(bool *res);

    string getText();
};

#endif // RECEIVER_H
