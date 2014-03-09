#ifndef SBPNEURON_H
#define SBPNEURON_H

#include <vector>

using namespace std;

class SBPNeuron
{
public:
    SBPNeuron(int ins);

    float answer(vector<float>) const;
    float answer_dy(vector<float>) const;
    void modify(vector<float>);
    float get_weight(int input) const;
    
    void printout() const;
    void load(vector<float>);
private:
    vector<float> weights;
};

#endif // NEURON_H
