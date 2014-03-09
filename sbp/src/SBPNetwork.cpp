#include "SBPNetwork.h"

SBPNetwork::SBPNetwork() {}

SBPNetwork::SBPNetwork(vector<int> arch)
{
    for (unsigned int i=1; i < arch.size(); ++i)
    {
        layers.push_back(SBPLayer(arch[i],arch[i-1]));
    }
}

vector<float> SBPNetwork::classify(vector<float> x) const
{
    vector<float> result=x;
    deque<SBPLayer>::const_iterator i;
    for (i=layers.begin(); i != layers.end(); ++i) {
        result=(*i).classify(result);
    }

    return result;
}

void SBPNetwork::train(vector<float> x,vector<float> d,float beta)
{
    vector<vector<float> > y;
    vector<vector<float> > dy;

    vector<float> answer=x;

    vector<vector<float> > delta(layers.size(),vector<float>());

    deque<SBPLayer>::iterator i;
    for (i = layers.begin(); i != layers.end(); ++i) {
        dy.push_back((*i).get_dy(answer));
        answer=(*i).classify(answer);
        y.push_back(answer);
    }


}

void SBPNetwork::load(vector<vector<vector<float> > > w) {
    //if (w.size() != layers.size()) throw exception();
    for (int i=0;i<layers.size();++i)
    {
        layers[i].load(w[i]);
    }
}

void SBPNetwork::load(istream& in) {
    
}

void SBPNetwork::printout() const {
    cout<<"LAYERS "<<layers.size()<<endl;
    for (deque<SBPLayer>::const_reverse_iterator i=layers.rbegin();i!=layers.rend();++i)
        (*i).printout();
    cout<<endl;
}

void SBPNetwork::add_layer(int inputs, int outputs) {
    layers.push_back(SBPLayer(inputs, outputs));
}

void SBPNetwork::add_layer(vector<vector<float> > weights) {
    SBPLayer layer(weights[0].size(), weights.size());
    layer.load(weights);
    layers.push_back(layer);
}
