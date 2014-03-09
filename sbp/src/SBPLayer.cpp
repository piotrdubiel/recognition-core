#include "SBPLayer.h"

#include <iostream>

SBPLayer::SBPLayer(int inputs,int outputs) {
    for (int i=0; i < outputs; ++i) {
        neurons.push_back(SBPNeuron(inputs));
    }
}

std::vector<float> SBPLayer::classify(std::vector<float> x) const {
    std::vector<float> result;
    std::vector<float>::const_iterator it;
    //cerr << "(";
    for (it=x.begin(); it!=x.end(); ++it) {
    //    cerr << *it << ", ";
    }
    //cerr << ")" << endl;
    std::deque<SBPNeuron>::const_iterator i;
    //cerr << "{";
    for (i=neurons.begin(); i != neurons.end(); ++i) {
        //cerr << (*i).answer(x) << ", ";
        result.push_back((*i).answer(x));
    }
    //cerr << "}" << endl;

    return result;
}

std::vector<float> SBPLayer::get_dy(std::vector<float> x) const {
    std::vector<float> result;
    std::deque<SBPNeuron>::const_iterator i;
    for (i=neurons.begin();i!=neurons.end();++i) {
        result.push_back((*i).answer_dy(x));
    }

    return result;
}

float SBPLayer::get_weight(int neuron, int input) const {
    return neurons[neuron].get_weight(input);
}

int SBPLayer::size() const {
    return neurons.size();
}

void SBPLayer::modify(int neuron, std::vector<float> mod) {
    neurons[neuron].modify(mod);
}

void SBPLayer::load(std::vector<std::vector<float> > w) {
    if (w.size() != neurons.size()) throw exception();
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
