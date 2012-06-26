#ifndef OPENCHANNEL_H
#define OPENCHANNEL_H

#include <string>
#include <vector>

using namespace std;

class OpenChannel
{
public:
    OpenChannel();
    int get_first();
    void add(int item);
    void add(vector<int> vec);

private:
    vector<int> msgQueue;
};

#endif // OPENCHANNEL_H
