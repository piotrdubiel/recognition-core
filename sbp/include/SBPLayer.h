#ifndef SBPLAYER_H
#define SBPLAYER_H

#include <deque>
#include <vector>
#include "SBPNeuron.h"

class SBPLayer {
public:
    SBPLayer(int,int);
    std::vector<float> classify(std::vector<float> x) const;
    std::vector<float> get_dy(std::vector<float> x) const;
    float get_weight(int neuron,int input) const;
    int size() const;

    void modify(int neuron,std::vector<float> mod);
    
    void printout() const;
    void load(std::vector<std::vector<float> > w);

private:
    deque<SBPNeuron> neurons;
};

#endif // LAYER_H
