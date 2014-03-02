#ifndef CNNNETWORK_H
#define CNNNETWORK_H

#include <deque>
#include <vector>
#include <iostream>
#include "CNNLayer.h"


class CNNNeuron;
class CNNWeight;
class CNNLink;

typedef std::vector<CNNLayer*> Layers;
typedef std::vector<CNNNeuron*> Neurons;
typedef std::vector<CNNWeight*> Weights;
typedef std::vector<CNNLink*> Links;

class CNNNetwork
{
private:
    Layers layers;
public:
    CNNNetwork();
    std::vector<float> classify(std::vector<float> input, std::vector<std::vector<float> >* neuron_outputs = NULL) const;
    void load();
};


#endif // CNNNETWORK_H
