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

    vector<float> answer = x;

    vector<vector<float> > delta(layers.size(),vector<float>());

    deque<SBPLayer>::iterator dit;
    for (dit = layers.begin(); dit != layers.end(); ++dit) {
        dy.push_back((*dit).get_dy(answer));
        answer=(*dit).classify(answer);
        y.push_back(answer);
    }

    float error = 0.0f;
    for (int i=0; i<y.back().size(); ++i) {
        error += (d[i] - y.back()[i])*(d[i] - y.back()[i]);
    }
    error /= 2;
    //std::cout << "Error: " << error << std::endl;

    // output layer
    for (int i=0; i<y.back().size(); ++i) {
        delta.back().push_back((d[i]-y.back()[i])*dy.back()[i]);
    }


    for (int l=layers.size()-2; l>=0; l--) {
        for (int j=0; j<y[l].size(); j++) {
            float sum = 0.0f;
            for (int n=0; n<layers[l+1].size(); ++n) {
                sum += delta[l+1][n] * layers[l+1].get_weight(n,j);
            }
            delta[l].push_back(sum * dy[l][j]);
        }
    }

//    cout<<"DELTA"<<endl;
//   for (vector<vector<float> >::iterator i=delta.begin();i!=delta.end();++i)
//   {
//       for (vector<float>::iterator j=(*i).begin();j!=(*i).end();++j)
//   cout<<(*j)<<" ";
//   cout<<endl;
//   }

   for (int k=1;k<layers.size();++k) {
       for (int n=0;n<layers[k].size();++n) {
           vector<float> mod;
           for (int l=0;l<layers[k-1].size();++l){
               mod.push_back(beta*delta[k-1][n]*y[k][l]);
           }
           mod.push_back(beta*delta[k-1][n]);
           layers[k-1].modify(n,mod);
       }
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
