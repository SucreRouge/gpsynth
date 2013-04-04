/*
  ==============================================================================

    NoiseNode.cpp
    Created: 6 Feb 2013 11:05:21am
    Author:  cdonahue

  ==============================================================================
*/

#include "NoiseNode.h"

/*
    ==============
    PUBLIC METHODS
    ==============
*/

NoiseNode::NoiseNode(GPRandom* r) {
    rng = r;
}

NoiseNode::~NoiseNode() {
}

NoiseNode* NoiseNode::getCopy() {
    return new NoiseNode(rng);
}

void NoiseNode::evaluateBlock(unsigned fn, double* t, unsigned nv, double* v, double* min, double* max, unsigned n, float* buffer) {
    *min = -1;
    *max = 1;

    if (fn == 0) {
        g_fScale = 2.0f / 0xffffffff;
        g_x1 = 0x67452301;
        g_x2 = 0xefcdab89;
    }

    /*
    for (unsigned i = 0; i < n; i++) {
        buffer[i] = rng->gauss();
    }
    */

    whitenoise(buffer, n, 1.0);

    /*
    for (unsigned i = 0; i < n; i++) {
        if (buffer[i] < -1.0 || buffer[i] > 1.0) {
            std::cout << buffer[i] << std::endl;
        }
    }
    */
}

/*
    http://musicdsp.org/showArchiveComment.php?ArchiveID=216
*/
void NoiseNode::whitenoise(
    float* _fpDstBuffer, // Pointer to buffer
    unsigned int _uiBufferSize, // Size of buffer
    float _fLevel ) // Noiselevel (0.0 ... 1.0)
{
    _fLevel *= g_fScale;

    while( _uiBufferSize-- )
    {
        g_x1 ^= g_x2;
        *_fpDstBuffer++ = g_x2 * _fLevel;
        g_x2 += g_x1;
    }
}

void NoiseNode::toString(bool printRange, std::stringstream& ss) {
    ss << "(whitenoise)";
}

void NoiseNode::updateMutatedParams() {
}