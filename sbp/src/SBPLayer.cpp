#include "SBPLayer.h"

#include <iostream>

SBPLayer::SBPLayer(int count,int inserts) {
    for (int i=0; i < count; ++i)
        neurons.push_back(SBPNeuron(inserts));
}

vector<float> SBPLayer::classify(vector<float> x) const {
    vector<float> result;
    deque<SBPNeuron>::const_iterator i;
    for (i=neurons.begin(); i != neurons.end(); ++i)
        result.push_back((*i).answer(x));

    return result;
}

vector<float> SBPLayer::get_dy(vector<float> x) const {
    vector<float> result;
    deque<SBPNeuron>::const_iterator i;
    for (i=neurons.begin();i!=neurons.end();++i)
        result.push_back((*i).answer_dy(x));

    return result;
}

float SBPLayer::get_weight(int neuron, int input) const {
    return neurons[neuron].get_weight(input);
}

int SBPLayer::size() const {
    return neurons.size();
}

void SBPLayer::modify(int neuron, vector<float> mod) {
    neurons[neuron].modify(mod);
}

void SBPLayer::load(vector<vector<float> > w) {
	//if (w.size() != neurons.size()) throw exception();
	for (int i=0; i < neurons.size(); ++i) {
		neurons[i].load(w[i]);
	}
}

void SBPLayer::printout() const {
	cout<<"Layer"<<endl;
    for (deque<SBPNeuron>::const_iterator i=neurons.begin();i!=neurons.end();++i) {
		(*i).printout();
		cout<<endl;
	}
}
