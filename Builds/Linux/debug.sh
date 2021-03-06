#!/bin/bash

set -e

#gdb --args ./build/GeneticProgrammingSynthesizer --target ./samples/PianoC5.wav --fft 256 --exp 3 --threshold 0.1 --fitnesstype 1 --numgenerations 2 --values 523.251 --popsize 5 --mid 4 --md 12 --ctype 0 --rselect 0 --cselect 0 --crosspercent 0.9 --mutatechance 0.0 --verbose

#gdb --args ./build/GeneticProgrammingSynthesizer --target ./samples/PianoC5.wav --seed 0 --fft 256 --exp 3 --threshold 0.1 --fitnesstype 1 --numgenerations 2 --values 523.251 --popsize 5 --mid 4 --md 12 --ctype 0 --rselect 0 --cselect 0 --crosspercent 0.9 --mutatechance 0.0 --verbose

#gdb --args ./build/GeneticProgrammingSynthesizer --target ./samples/AMAnswer.wav --fft 1024 --exp 1 --threshold 0.01 --fitnesstype 1 --numgenerations 100 --values 440 1 --popsize 500 --mid 4 --md 5 --ctype 0 --rselect 0 --cselect 0 --crosspercent 0.9 --mutatechance 0.0 --verbose

#gdb --args ./build/GeneticProgrammingSynthesizer --target ./samples/SinWaveC51024.wav --fft 1024 --exp 4 --threshold 0.1 --fitnesstype 1 --numgenerations 2 --values 523.251 --popsize 5 --mid 4 --md 10 --ctype 0 --rselect 0 --cselect 0 --crosspercent 0.9 --mutatechance 0.0 --verbose

#gdb --args ./build/GeneticProgrammingSynthesizer --target ./samples/TrumpetEb5.wav --fft 1024 --exp 4 --threshold 0.1 --fitnesstype 1 --numgenerations 2 --values 622.25 --popsize 5 --mid 1 --md 1 --ctype 0 --rselect 0 --cselect 0 --crosspercent 0.9 --mutatechance 0.0 --verbose

#gdb --args ./build/GeneticProgrammingSynthesizer --target ./samples/TrumpetEb5.wav --verbose --precision 3 --values 622.25 --fft 1024 --fitnesstype 1 --experiment 4 --generations 4 --erc --popsize 20 --mid 1 -- md 3 --numericmutation 0.5 --nmselect 1 --nmselectparam 0.05 --nmtemperature 0.9 --crossover 0.9 --cselect 0 --ctype 0 --reproduction 0.05 --rselect 0

#gdb --args ./build/GeneticProgrammingSynthesizer --target ./samples/TrumpetEb5.wav --verbose --precision 3 --values 622.25 --fft 1024 --fitnesstype 1 --enviter 3 --experiment 4 --generations 3 --erc --popsize 20 --mid 5 -- md 11 --numericmutation 0.05 --nmselect 1 --nmselectparam 0.05 --nmtemperature 0.9 --mutation 0.05 --mtype 1 --mselectparam 0.25 --crossover 0.9 --cselect 0 --ctype 0 --reproduction 0.05 --rselect 0 --render 1024 --seed 24531

#gdb --args ./build/GeneticProgrammingSynthesizer

#gdb --args ./build/GPAudioTargetMatchingExperiment --target ./samples/PianoC5.wav --verbose --precision 3 --values 622.25 --fft 1024 --fitnesstype 1 --enviter 3 --experiment 8 --generations 0 --erc --popsize 0 --mid 5 -- md 11 --numericmutation 0.05 --nmselect 1 --nmselectparam 0.05 --nmtemperature 0.9 --mutation 0.05 --mtype 1 --mselectparam 0.25 --crossover 0.9 --cselect 0 --ctype 0 --reproduction 0.05 --rselect 0 --render 1024 --seed 245316

gdb --args \
  ./build/GPAudioTargetMatchingExperiment\
  TEMP FIELDS\
  --target ./samples/TrumpetEb5.wav\
  --path ./\
  --seed 24531\
  --values 622.25\
  --expinfo\
  EXPERIMENT PARAMS\
  --experiment 4\
  --fitnesstype 1\
  --generations 1\
  --threshold 0.1\
  --erc\
  AUXILLARY PARAMS\
  --verbose\
  --savegenchamps\
  --printprecision 3\
  --saveprecision 5\
  --loadwavblock 512\
  --render 1024\
  FITNESS FUNCTION WEIGHTS\
  --ffmagweight 1.0\
  --ffphaseweight 0.2\
  --ffenvweight 0.5\
  TIME DOMAIN PARAMS\
  --nosavetargetenv\
  --envatk 1\
  --envdcy 300\
  --envskip 9\
  FREQUENCY DOMAIN PARAMS\
  --window hann\
  --fft 1024\
  --fftoverlap 0\
  --ampmag\
  --averagetype 0\
  --averageradius 10\
  --phasepenalty 2.0\
  --goodmagcomp 0.1\
  --badmagcomp 1.1\
  --basemagcomp 0.9\
  SYNTH EVO PARAMS\
  --popsize 200\
  --nobackup\
  --backupprecision 50\
  --bestfitness 0.0\
  --mid 5\
  --md 11\
  SYNTH GENETIC PARAMS\
  --greedy 0.0\
  --numericmutation 0.05 --nmselect 1 --nmselectparam 0.05 --nmtemperature 0.9\
  --mutation 0.05 --mselect 1 --mtype 1 --mselectparam 0.25\
  --crossover 0.9 --cselect 0 --ctype 0\
  --reproduction 0.05 --rselect 0

gdb --args \
./build/GPAudioTargetMatchingExperiment\
  --target ./samples/TrumpetEb5.wav\
  --path ./\
  --seed 245316\
  --verbose\
  --savegenchamps\
  --expinfo\
  --precision 3\
  --values 622.25\
  --fft 1024\
  --fitnesstype 1\
  --enviter 3\
  --experiment 4\
  --generations 100\
  --threshold 0.1\
  --erc\
  --popsize 2000\
  --mid 5\
  --md 11\
  --numericmutation 0.05 --nmselect 1 --nmselectparam 0.05 --nmtemperature 0.9\
  --mutation 0.05 --mtype 1 --mselctparam 0.25\
  --crossover 0.9 --cselect 0 --ctype 0\
  --reproduction 0.05 --rselect 0\
  --render 1024

set +e
