#ifndef NODE_H
#define NODE_H

#include <Qt/qobject.h>

#include "../qbit.h"
#include <channels/quantumchannel.h>
#include <channels/openchannel.h>

struct KeyDescriptor
{
    bool polarization_type;
    bool bit;
    bool isActive;
    KeyDescriptor(bool polarization_type, bool bit, bool isActive) : polarization_type(polarization_type), bit(bit), isActive(isActive) {};
};

class Node : public QObject
{
    Q_OBJECT
public:
    Node(QuantumChannel* qChannel, OpenChannel* oChannel) : qChannel(qChannel), oChannel(oChannel)
    {
        clearKey();
    };
    static char* alphabet;

    void calcActiveKey();
    void clearKey();
    string getActiveKey();
    Q_INVOKABLE QString getActiveKeyQ();
    OpenChannel* oChannel;

protected:
    string activeKey;
    QuantumChannel* qChannel;

    vector<KeyDescriptor> key;

};

#endif // NODE_H
