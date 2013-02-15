/*
  ==============================================================================

    GPExperiment.h
    Created: 6 Feb 2013 7:19:38pm
    Author:  cdonahue

  ==============================================================================
*/

#ifndef GPEXPERIMENT_H
#define GPEXPERIMENT_H

#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include "Synth/GPNetwork.h"
#include <stdlib.h>

class GPSynth {
    public:
        GPSynth(int psize);
        ~GPSynth();

        void initPopulation();
        void prevGeneration();
        void nextGeneration();

        GPNodeParams* nodeParams;

    private:
        // experiment state
        int populationSize;
        int nextNetworkID;
        int generationID;
        double maxFitness;

        // network containers
        std::vector<GPNetwork*> allNetworks;
        std::map<GPNetwork*, double> upForEvaluation;
        std::vector<GPNetwork*> evaluated;
};

#endif
