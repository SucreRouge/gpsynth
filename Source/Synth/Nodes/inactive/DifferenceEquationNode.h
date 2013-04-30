/*
  ==============================================================================

    DifferenceEquationNode.h
    Created: 6 Feb 2013 11:05:21am
    Author:  cdonahue

  ==============================================================================
*/

#ifndef DIFFERENCEEQUATION_H
#define DIFFERENCEEQUATION_H

#include "../GPNode.h"

class DifferenceEquationNode: public GPNode {
public:
    DifferenceEquationNode(unsigned m, unsigned n, GPRandom* r, bool erc, GPMutatableParam* z, GPMutatableParam* p, GPNode* signal);
    DifferenceEquationNode(std::vector<GPMutatableParam*>& xcoef, std::vector<GPMutatableParam*>& ycoef, GPNode* signal);
    ~DifferenceEquationNode();

	// overrides
    DifferenceEquationNode* getCopy();
	void prepareToPlay();
    void evaluateBlock(unsigned fn, double* t, unsigned nv, double* v, double* min, double* max, unsigned n, float* buffer);
	void evaluateBlockPerformance(unsigned fn, float* t, unsigned nv, float* v, float* min, float* max, unsigned n, float* buffer);
	void getRangeTemp(float* min, float* max);
	void updateMutatedParams();
    void toString(bool printRange, std::stringstream& ss);

private:
    // difference equation zeroes
    unsigned numXCoefficients;
    std::vector<GPMutatableParam*> xcoefficients;
    float* xcoefs;
    float* x;

    // difference equation poles
    unsigned numYCoefficients;
    std::vector<GPMutatableParam*> ycoefficients;
    float* ycoefs;
    float* y;
};

#endif