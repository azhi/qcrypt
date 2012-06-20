#include "openchannel.h"

OpenChannel::OpenChannel()
{
    msgQueue.clear();
}

int OpenChannel::read_first()
{
    return msgQueue.front();
}

int OpenChannel::get_first()
{
    if (msgQueue.size() > 0)
    {
        int res = msgQueue.front();
        msgQueue.erase(msgQueue.begin());
        return res;
    }
    return -1;
}

void OpenChannel::add(int item)
{
    msgQueue.push_back(item);
}

void OpenChannel::add(vector<int> vec)
{
    msgQueue.insert(msgQueue.end(),vec.begin(),vec.end());
}
