// DO NOT MODIFY THE HEADERS IF FORZE IS ALREADY COMPILED AS A STATIC LIBRARY
#ifndef __FZMATRIXSTACK_H_INCLUDED__
#define __FZMATRIXSTACK_H_INCLUDED__
/*
 * FORZE ENGINE: http://forzefield.com
 *
 * Copyright (c) 2011-2012 FORZEFIELD Studios S.L.
 * Copyright (c) 2012 Manuel Martínez-Almeida
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 @author Manuel Martínez-Almeida
 */

#include "FZTypes.h"


namespace FORZE {
        
    void fzMS_initialize();
    void fzMS_dealloc();

    void fzMS_loadMatrix(float *matrix);
    void fzMS_loadBaseMatrix(float *matrix);
    
    void fzMS_pushMatrix(float *matrix);
    void fzMS_pop();
    
    fzUInt fzMS_getLevel();
    float* fzMS_getMatrix();
    float* fzMS_getBaseMatrix();
    
#define APPLY_MATRIX(__SHADER__) { \
FZ_ASSERT(__SHADER__ != NULL, "Shader can not be NULL"); \
FZ_ASSERT(fzMS_getMatrix() != NULL, "Stack base can not be NULL"); \
(__SHADER__)->setUniform4x4f(kFZUniformMVMatrix_s, 1, GL_FALSE, fzMS_getMatrix()); \
}

}

#endif