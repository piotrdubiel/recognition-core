#include "SBPNetwork.h"
#include <vector>
#include <iostream>

int main()
{
    SBPNetwork * net = new SBPNetwork();
    net->add_layer(2, 2);
    net->add_layer(2, 1);


    std::vector<std::vector<float> > examples;
    examples.push_back(std::vector<float>());
    examples[0].push_back(0.0f);
    examples[0].push_back(0.0f);
    examples.push_back(std::vector<float>());
    examples[1].push_back(1.0f);
    examples[1].push_back(0.0f);
    examples.push_back(std::vector<float>());
    examples[2].push_back(0.0f);
    examples[2].push_back(1.0f);
    examples.push_back(std::vector<float>());
    examples[3].push_back(1.0f);
    examples[3].push_back(1.0f);

    std::vector<std::vector<float> > labels;
    labels.push_back(std::vector<float>());
    labels[0].push_back(0);
    labels.push_back(std::vector<float>());
    labels[1].push_back(1);
    labels.push_back(std::vector<float>());
    labels[2].push_back(1);
    labels.push_back(std::vector<float>());
    labels[3].push_back(0);

    std::cout << "Result[" << net->classify(examples[0]).size() << "]: " << net->classify(examples[0]).front() << " " << net->classify(examples[0]).back() << std::endl;
    std::cout << "Result: " << net->classify(examples[1]).front() << " " << net->classify(examples[1]).back() << std::endl;

    for (int e=0; e<50; e++) {
        for (int i=0; i<examples.size(); ++i) {
            net->train(examples[i], labels[i], 0.1f);
        }
    }

    net->printout();

    std::cout << "Result[" << net->classify(examples[0]).size() << "]: " << net->classify(examples[0]).front() << " " << net->classify(examples[0]).back() << std::endl;
    std::cout << "Result: " << net->classify(examples[1]).front() << " " << net->classify(examples[1]).back() << std::endl;

    delete net;
    return 0;
}
