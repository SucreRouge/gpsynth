#!/bin/bash

set -e

gdb --args ./build/GeneticProgrammingSynthesizer --target ./samples/PianoC5.wav --fft 256 --exp 3 --threshold 0.1 --fitnesstype 1 --numgenerations 2 --values 523.251 --popsize 5 --mid 4 --md 12 --ctype 0 --rselect 0 --cselect 0 --crosspercent 0.9 --mutatechance 0.0 --verbose

set +e
