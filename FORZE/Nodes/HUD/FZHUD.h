// DO NOT MODIFY THE HEADERS IF FORZE IS ALREADY COMPILED AS A STATIC LIBRARY
#ifndef __FZHUD_H_INCLUDED__
#define __FZHUD_H_INCLUDED__
/*
 * FORZE ENGINE: http://forzefield.com
 *
 * Copyright (c) 2011-2012 FORZEFIELD Studios S.L.
 * Copyright (c) 2012 Manuel Martínez-Almeida
 * Copyright (c) 2008-2010 Ricardo Quesada
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

#include "FZScene.h"


namespace FORZE {
    
    class HUDProtocol
    {
    public:
        virtual bool needsFPS() const = 0;
        virtual bool needsMemory() const = 0;

        virtual void setFrame(fzFloat) {}
        virtual void setMemory(fzUInt) {}
    };
    
    class Label;
    class HUD : public Scene, public HUDProtocol
    {
    protected:
        Label *p_FPSLabel;
        fzVec2 *m_vertices;
        fzInt m_count;
        fzInt m_index;
        bool m_background;
        
        virtual void updateStuff() override;
        virtual void draw() override;
        
    public:
        HUD();
        ~HUD();
        
        bool needsFPS() const;
        bool needsMemory() const;

        void setFrame(fzFloat);
        
        virtual void updateLayout() override;
        
    };
}
#endif
