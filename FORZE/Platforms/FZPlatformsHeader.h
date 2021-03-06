// DO NOT MODIFY THE HEADERS IF FORZE IS ALREADY COMPILED AS A STATIC LIBRARY
#ifndef __FZPLATFORMSHEADER_H_INCLUDED__
#define __FZPLATFORMSHEADER_H_INCLUDED__
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

#ifdef __cplusplus
#if __cplusplus <= 199711L
#error "This library needs at least a C++11 compliant compiler."
#error "Set the C++ Language Dialect to [-std=c++11]"

#endif
#else
#error "C++ is not available. Maybe the compilers is not compiling the header files as C++ files."
#endif



/** @def kFZPLATFORM_IOS_GL_1
 * iOS. Opengl ES 1.0 rendering. ARMv6 and ARMv7. All iDevices.
 */
#define kFZPLATFORM_IOS_GL_1 0


/** @def kFZPLATFORM_IOS_GL_2
 * iOS. Opengl ES 2.0 rendering. Shader. Only available for ARMv7 iDevices.
 */
#define kFZPLATFORM_IOS_GL_2 1


/** @def kFZPLATFORM_IOS_GL_2
 * Mac OS X. Opengl 1.1 rendering. Shaders.
 */
#define kFZPLATFORM_MAC 2


/** @def kFZPLATFORM_PSVITA
 * Playstation VITA. Shaders.
 */
#define kFZPLATFORM_PSVITA 3


/** @def kFZPLATFORM_WINDOWS
 * Windows. OpenGL. Shaders.
 */
#define kFZPLATFORM_WINDOWS 4


#define kFZPLATFORM_ANDROID 5

#endif
