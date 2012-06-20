#include "node.h"
#include <math.h>
#include <string.h>

char* Node::alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !@#$%^&*()_";

void Node::calcActiveKey()
{
    vector<KeyDescriptor>::iterator curQB = key.begin();
    while ( curQB != key.end() )
    {
        int i;
        unsigned char res = 0;
        for( i=0; i<6 && curQB != key.end(); ++i )
        {
            if ( curQB->isActive && curQB->bit )
                res += pow(2, 5-i);
            curQB++;
        }
        activeKey.insert(activeKey.end(), alphabet[res]);
    }
}
