#include "include/ann.h"
#include "include/Network.h"
#include <vector>

ann::ann()
{
    std::vector<int> arch;
    arch.push_back(80);
    arch.push_back(60);
    arch.push_back(10);

    Network * net = new Network(arch);
}
