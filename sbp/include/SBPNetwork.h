#ifndef SBPNETWORK_H
#define SBPNETWORK_H

#include <deque>
#include <vector>
#include <iostream>
#include "SBPLayer.h"

using namespace std;

class SBPNetwork
{
public:
    SBPNetwork();
    SBPNetwork(vector<int> arch);

    vector<float> classify(vector<float> x) const;
    void train(vector<float> x,vector<float> w,float beta);
    void load(string filename);
    void load(vector<vector<vector<float> > > w);
    void load(istream& in);

    void printout() const;
    void add_layer(int, int);
    void add_layer(vector<vector<float> >);
private:
    deque<SBPLayer> layers;
};

#endif // NETWORK_H
