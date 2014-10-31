#ifndef CHANNEL_H
#define CHANNEL_H

#include <string>

using namespace std;

class channel {
private:
    string name;
public:
    channel() = default;
    channel(string name);
};

#endif // CHANNEL_H
