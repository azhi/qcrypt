#ifndef INTERCEPTER_H
#define INTERCEPTER_H

#include "node.h"

class Intercepter : public Node
{
public:
    Intercepter(QuantumChannel* qChannel, OpenChannel* oChannel) : Node(qChannel, oChannel) {};
    void interceptQBit();
    vector<int> interceptMsg();

    void interceptTypeInfo(int keyLength);
    void interceptCorrectIndexes();
    void interceptCheck();

    string interceptText();

    void clearKey();

private:
    vector<KeyDescriptor> rcverKey;
};

#endif // INTERCEPTER_H
