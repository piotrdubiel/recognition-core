#include "SBPNeuron.h"

#include <stdlib.h>
#include <iostream>
//#include <exception>
#include <cmath>

SBPNeuron::SBPNeuron(int ins) {
    for (int i=0; i <= ins; ++i) {
        weights.push_back(((rand()%100000+1)/100000.0f-0.5f) / sqrt((float) ins));
    }
}

float SBPNeuron::answer(vector<float> x) const {
    x.push_back(1.0f);
    if (x.size() != weights.size()) {
        //cerr<<"vector size error "<<x.size()<<" should be "<<weights.size()<<endl;
        vector<float>::iterator it;
        //cerr <<"[";
        for (it=x.begin(); it!=x.end(); ++it) {
         //   cerr << *it <<", ";
        }
        //cerr <<"]" << endl;
        throw new exception();
    }

	float result = 0.0f;
    for (int i=0; i < weights.size(); ++i) {
        result+=weights[i]*x[i];
    }

	return (1.0f / (1.0f + exp(-result)));
}

float SBPNeuron::answer_dy(vector<float> x) const
{
	float result = 0.0f;
    for (int i=0; i < weights.size();++i)
        result += weights[i]*x[i];

    float exp_from_result = exp(-result);
    return exp_from_result / (1 + exp(-result)) / (1 + exp(-result));
}

void SBPNeuron::modify(vector<float> mod)
{
    if (mod.size() != weights.size()) {
        cerr<<"mod size error "<<mod.size()<<" should be "<<weights.size()<<endl;
        throw new std::exception();
    }

    for (int i=0;i<weights.size();++i) {
        weights[i]+=mod[i];
    }

    //bias+=mod.back();
}

float SBPNeuron::get_weight(int input) const
{
    return weights[input];
}


void SBPNeuron::printout() const {
    for (vector<float>::const_iterator i=weights.begin();i!=weights.end();++i) {
		cout<<(*i)<<" ";
    }
}

void SBPNeuron::load(vector<float> w) {
	weights.clear();
	weights.assign(w.begin(),w.end());
}
