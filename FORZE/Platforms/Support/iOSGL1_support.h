// DO NOT MODIFY THE HEADERS IF FORZE IS ALREADY COMPILED AS A STATIC LIBRARY
#ifndef __FZSUPPORT_IOS1_H_INCLUDED__
#define __FZSUPPORT_IOS1_H_INCLUDED__
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


#if defined(FZ_OS) && (FZ_OS == kFZPLATFORM_IOS_GL_1)

// Import iOS stuff
#include "iOS_support.h"

// Import OpenGL ES 1.0 headers
#include <OpenGLES/EAGL.h>
#include <OpenGLES/EAGLDrawable.h>
#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>


#pragma mark - OpenGL Config

#define FZ_GL_PVRTC 1
#define FZ_GL_SHADERS 0


#pragma mark - OpenGL API

#define	fzGLClearDepth				glClearDepthf
#define fzGLGenerateMipmap			glGenerateMipmapOES
#define FZ_MAX_TEXTURE_SIZE         GL_MAX_TEXTURE_SIZE
#define FZ_MAX_SAMPLES              GL_MAX_SAMPLES_APPLE
#define FZ_FRAMEBUFFER              GL_FRAMEBUFFER_OES
#define FZ_FRAMEBUFFER_BINDING      GL_FRAMEBUFFER_BINDING_OES
#define FZ_FRAMEBUFFER_COMPLETE     GL_FRAMEBUFFER_COMPLETE_OES

#define fzGLGenFramebuffers			glGenFramebuffersOES
#define _fzGLBindFramebuffer		glBindFramebufferOES
#define fzGLFramebufferTexture2D	glFramebufferTexture2DOES
#define fzGLCheckFramebufferStatus  glCheckFramebufferStatusOES
#define fzGLDeleteFramebuffers		glDeleteFramebuffersOES

#define fzGLGenRenderbuffers        glGenRenderbuffersOES
#define fzGLBindRenderbuffer        glBindRenderbufferOES
#define fzGLFramebufferRenderbuffer	glFramebufferRenderbufferOES
#define fzGLRenderbufferStorage     glRenderbufferStorageOES
#define fzGLGetRenderbufferParameteriv glGetRenderbufferParameterivOES

#define FZ_RENDERBUFFER             GL_RENDERBUFFER_OES
#define FZ_COLOR_ATTACHMENT0		GL_COLOR_ATTACHMENT0_OES
#define FZ_DEPTH_ATTACHMENT         GL_DEPTH_ATTACHMENT_OES
#define FZ_RENDERBUFFER_WIDTH       GL_RENDERBUFFER_WIDTH_OES
#define FZ_RENDERBUFFER_HEIGHT      GL_RENDERBUFFER_HEIGHT_OES



#pragma mark - OS WRAPPER

@interface _FZOSWRAPPER : _FZOSWRAPPER_BASE
@end

#endif
#endif