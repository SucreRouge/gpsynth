/*
  ==============================================================================

    ConstantNode.h
    Created: 6 Feb 2013 11:06:13am
    Author:  cdonahue

  ==============================================================================
*/

#ifndef CONSTANTNODE_H
#define CONSTANTNODE_H

#include "../GPNode.h"

class ConstantNode: public GPNode {
public:
    ConstantNode(GPMutatableParam* v);
    ~ConstantNode();

	// overrides
    ConstantNode* getCopy();
	void prepareToPlay();
    void evaluateBlock(unsigned fn, double* t, unsigned nv, double* v, double* min, double* max, unsigned n, float* buffer);
	void evaluateBlockPerformance(unsigned fn, float* t, unsigned nv, float* v, float* min, float* max, unsigned n, float* buffer);
	void getRange(float* min, float* max);
	void updateMutatedParams();
    void toString(bool printRange, std::stringstream& ss);

private:
    double value;
    double minimum;
    double maximum;
};

#endif
