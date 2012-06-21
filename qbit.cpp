#include "qbit.h"
#include <stdlib.h>

bool QBit::getValue(bool valType)
{
    bool res;
    if (valType == type)
        res = value;
    else
        res = rand() % 2;
    value = rand() % 2;
    return res;
}
