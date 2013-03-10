/*
  ==============================================================================

    GPNode.h
    Created: 6 Feb 2013 11:06:00am
    Author:  cdonahue

  ==============================================================================
*/

#ifndef GPNODE_H
#define GPNODE_H

#include "../Common/GPParams.h"
#include "../Common/GPMutatableParam.h"
#include <vector>
#include <algorithm>

class GPNode {
    public:
        GPNode()
            : parent(NULL), left(NULL), right(NULL), 
                isBinary(false), isTerminal(false),
                mutatableParams()
            {
            }

        // PURE VIRTUAL METHODS THAT ALL SUBCLASSES WILL IMPLEMENT
        virtual double evaluate(double* t, double* v) = 0;
        virtual void evaluateBlock(double* t, double** v, unsigned n, float* buffer) = 0;
        virtual std::string toString() = 0;
        virtual GPNode* getCopy() = 0;
        virtual void mutate(GPParams* e) = 0;
        // EVALUATE BLOCK
        // GET MUTABLE COEFFICIENTS

        // HERITAGE POINTERS
        GPNode* parent;
        GPNode* left;
        GPNode* right;

        // INDICATORS ABOUT TYPE
        bool isBinary;
        bool isTerminal;

        // MUTATABLE PARAMS
        std::vector<GPMutatableParam*> mutatableParams;

        // INHERITED TRACE METHOD
        void traceSubtree(std::vector<GPNode*>* allnodes, std::vector<GPMutatableParam*>* allparams, GPNode* p, int* rootHeight, int currentDepth) {
            parent = p;
            allnodes->push_back(this);
            for (int i = 0; i < mutatableParams.size(); i++) {
                allparams->push_back(mutatableParams[i]);
            }
            if (currentDepth > *rootHeight) {
                *rootHeight = currentDepth;
            }
            if (!isTerminal) {
                left->traceSubtree(allnodes, allparams, this, rootHeight, currentDepth + 1);
                if (isBinary) {
                    right->traceSubtree(allnodes, allparams, this, rootHeight, currentDepth + 1);
                }
            }
        };
};

#endif
