#ifndef LAYER_H
#define LAYER_H

#include <deque>
#include <vector>
#include "SBPNeuron.h"

using namespace std;


class SBPLayer

{
public:
    SBPLayer(int count,int inserts);
    vector<float> classify(vector<float> x) const;
    vector<float> get_dy(vector<float> x) const;
    float get_weight(int neuron,int input) const;
    int size() const;

    void modify(int neuron,vector<float> mod);
    
    void printout() const;
    void load(vector<vector<float> > w);

private:
    deque<SBPNeuron> neurons;
};

#endif // LAYER_H
