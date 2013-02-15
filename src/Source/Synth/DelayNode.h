/*
  ==============================================================================

    DelayNode.h
    Created: 6 Feb 2013 11:05:21am
    Author:  cdonahue

  ==============================================================================
*/

#ifndef DELAYNODE_H
#define DELAYNODE_H

#include <stdio.h>
#include "GPNode.h"
#include <list>

class DelayNode: public GPNode {
    public:
        DelayNode(int n, GPNode* l, GPNode* r);
        ~DelayNode();
        DelayNode* getCopy();

        void setMemoryConstants(int x, int y);
        double evaluate(double* t, double* v);
        std::string toString();
        void mutate(GPNodeParams* e);

    private:
        int numFilled;

        int numSamples;
        std::list<double> delayLine;
};

#endif
