#include "node.h"
#include <math.h>
#include <string.h>

char* Node::alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !@#$%^&*()_";

void Node::calcActiveKey()
{
    vector<KeyDescriptor>::iterator curQB = key.begin();
    while ( curQB != key.end() )
    {
        unsigned char res = 0;
        int i = 0;
        while ( i < 6 && curQB != key.end() )
        {
            if ( curQB->isActive )
            {
                i++;
                if ( curQB->bit )
                    res += pow(2, 5-i);
            }
            curQB++;
        }
        activeKey.insert(activeKey.end(), alphabet[res]);
    }
}
