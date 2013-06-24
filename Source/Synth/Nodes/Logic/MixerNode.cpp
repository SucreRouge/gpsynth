/*
  ==============================================================================

    MixerNode.cpp
    Author:  cdonahue

  ==============================================================================
*/

#include "MixerNode.h"

/*
    ========================
    CONSTRUCTION/DESTRUCTION
    ========================
*/

MixerNode::MixerNode(GPNode* mod, GPNode* sigone, GPNode* sigtwo) {
    arity = 3;
    descendants.push_back(mod);
    descendants.push_back(sigone);
    descendants.push_back(sigtwo);
}

MixerNode::~MixerNode() {
}

/*
    =========
    OVERRIDES
    =========
*/

MixerNode* MixerNode::getCopy() {
    return new MixerNode(descendants[0] == NULL ? NULL : descendants[0]->getCopy(), descendants[1] == NULL ? NULL : descendants[1]->getCopy(), descendants[2] == NULL ? NULL : descendants[2]->getCopy());
}

void MixerNode::evaluateBlockPerformance(unsigned firstFrameNumber, unsigned numSamples, float* sampleTimes, unsigned numConstantVariables, float* constantVariables, float* buffer) {
    descendants[0]->evaluateBlockPerformance(firstFrameNumber, numSamples, sampleTimes, numConstantVariables, constantVariables, buffer);
    descendants[1]->evaluateBlockPerformance(firstFrameNumber, numSamples, sampleTimes, numConstantVariables, constantVariables, descendantBuffers[0]);
    descendants[2]->evaluateBlockPerformance(firstFrameNumber, numSamples, sampleTimes, numConstantVariables, constantVariables, descendantBuffers[1]);

    for (unsigned i = 0; i < numSamples; i++) {
        float levelone;
        float leveltwo;
        buffer[i] = descendantBuffers[0][i] * levelone + descendantBuffers[1][i] * leveltwo;
    }
}

void MixerNode::updateMutatedParams() {
    GPNode::updateMutatedParams();

    // update min/max values from descendants
    float signalOneMin = descendants[1]->minimum;
    float signalOneMax = descendants[1]->maximum;
    float signalTwoMin = descendants[2]->minimum;
    float signalTwoMax = descendants[2]->maximum;
    minimum = signalOneMin < signalTwoMin ? signalOneMin : signalTwoMin;
    maximum = signalOneMax > signalTwoMax ? signalOneMax : signalTwoMax;
}

void MixerNode::toString(std::stringstream& ss) {
    ss << "(mix ";
    descendants[0]->toString(ss);
    ss << " ";
    descendants[1]->toString(ss);
    ss << " ";
    descendants[2]->toString(ss);
    ss << ")";
}
