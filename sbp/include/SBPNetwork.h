#ifndef NETWORK_H
#define NETWORK_H

#include <deque>
#include <vector>
#include <iostream>
#include "SBPLayer.h"

using namespace std;

class SBPNetwork
{
public:
    SBPNetwork(vector<int> arch);

    vector<float> classify(vector<float> x) const;
    void train(vector<float> x,int ident,float beta);
    void train(vector<float> x,vector<float> w,float beta);
    void load(string filename);
    void load(vector<vector<vector<float> > > w);
    void load(istream& in);

    void printout() const;
private:
    deque<SBPLayer> layers;
};

#endif // NETWORK_H
