#ifndef NODE_H
#define NODE_H

#include <qbit.h>
#include <channels/quantumchannel.h>
#include <channels/openchannel.h>

struct KeyDescriptor
{
    bool polarization_type;
    bool bit;
    bool isActive;
    KeyDescriptor(bool polarization_type, bool bit, bool isActive) : polarization_type(polarization_type), bit(bit), isActive(isActive) {};
};

class Node
{
public:
    Node(QuantumChannel* qChannel, OpenChannel* oChannel) : qChannel(qChannel), oChannel(oChannel)
    {
        key.clear();
        activeKey.clear();
    };
    static char* alphabet;

    void calcActiveKey();
    string activeKey;

protected:
    QuantumChannel* qChannel;
    OpenChannel* oChannel;
    vector<KeyDescriptor> key;

};

#endif // NODE_H
