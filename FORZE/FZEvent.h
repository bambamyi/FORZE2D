// DO NOT MODIFY THE HEADERS IF FORZE IS ALREADY COMPILED AS A STATIC LIBRARY
#ifndef __FZEVENT_H_INCLUDED__
#define __FZEVENT_H_INCLUDED__
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

#include <ctime>
#include "FZTypes.h"


namespace FORZE {
    
    enum fzEventState
    {
        //! The event began
        kFZEventState_Began,
        
        //! The event's values were updated
        kFZEventState_Updated,
        
        //! The event ended
        kFZEventState_Ended,
        
        kFZEventState_Cancelled,
        
        //! The event state is indifferent
        //! @see kFZEventType_Accelerometer
        kFZEventState_Indifferent
    };
    
    
    enum fzEventType
    {
        kFZEventType_None           = 0,
        
        //! Application events
        //! The state is a aproximation to the application state
        //! kFZEventState_Began = Application resumed
        //! kFZEventState_Ended = Application paused
        //! kFZEventState_Cancelled = Application terminated
        kFZEventType_Application    = 1 << 0,

        //! Screen touching events
        //! This kind of events returns an position in the canvas
        kFZEventType_Touch          = 1 << 1,
        
        //! Mouse left events
        //! This kind of events returns an position in the canvas
        kFZEventType_Mouse          = 1 << 2,
        
        //! Mouse right events
        //! This kind of events returns an position in the canvas
        kFZEventType_MouseRight    = 1 << 3,
        
        kFZEventType_MouseMoved      = 1 << 4,
        
        //! Keyboard events
        //! This kind of events returns the key pressed
        kFZEventType_Keyboard       = 1 << 5,
        
        //! Trackpad touching events
        //! This kind of events returns an normalized position [0, 1]
        kFZEventType_Trackpad       = 1 << 6,
        
        //! Accelerometer events
        //! @warning this event kind just has a state. kFZEventState_Indifferent
        //! @see kFZEventState_Indifferent
        kFZEventType_Accelerometer  = 1 << 7,
        
        //! Gyroscope events
        //! @warning this event kind just has a state. kFZEventState_Indifferent
        //! @see kFZEventState_Indifferent
        kFZEventType_Gyro           = 1 << 8,
        
        
        //! Joystick event
        //! This kind of events returns an normalized vector [0, 1]
        kFZEventType_Stick          = 1 << 9,
        

        
        
        
        //! Tap events are a cross platform solution. It's equivalent to:
        //! kFZEventType_Touch in mobile devices (iPhone, Android...)
        //! kFZEventType_Mouse in desktop devices (Mac OSX, Windows, Linux)
        kFZEventType_Tap = kFZEventType_Touch | kFZEventType_Mouse
    };
        
    class EventDelegate;
    class Event
    {
        friend class EventManager;
        
    private:
        //! type of event
        fzEventType m_type;
        
        //! state
        fzEventState m_state;
        
        //! creating time
        time_t m_creation;
        
        //! unique identifier
        intptr_t m_identifier;
        
        //! values
        double m_x, m_y, m_z;
        
        //! delegate
        EventDelegate *p_delegate;
      
        //! owner
        void *p_owner;
        
        //! user data
        void *p_userData;
        
        void update(const Event& event);
        
        
        //! method used internally to change the event's delegate
        void setDelegate(EventDelegate* d);
        
        //! method used internally to get the event's type
        fzEventType getType() const {
            return m_type;
        }
        
        
    public:
        //! Constructs a new events to be managed by the EventManager
        //! @param identifier. Must be unique identifier used to track the life cicle of the event. Began, Updated, Ended...
        Event(void *owner, intptr_t identifier, fzEventType type, fzEventState state, fzFloat x, fzFloat y, fzFloat z)
        : p_owner(owner)
        , m_identifier(identifier)
        , m_type(type)
        , m_state(state)
        , m_x(x)
        , m_y(y)
        , m_z(z)
        , p_delegate(NULL)
        , p_userData(NULL)
        {
            if(state == kFZEventState_Began)
                time(&m_creation);
        }
        
        
        Event(void *owner, intptr_t identifier, fzEventType type, fzEventState state, fzPoint point, fzFloat scalar)
        : Event(owner, identifier, type, state, point.x, point.y, scalar) {}

        
        Event(void *owner, intptr_t identifier, fzEventType type, fzEventState state, fzPoint3 point3)
        : Event(owner, identifier, type, state, point3.x, point3.y, point3.z) {}
      
      
        Event(void *owner, intptr_t identifier, fzEventType type, fzEventState state)
        : Event(owner, identifier, type, state, 0, 0, 0) {}
        
        
        //! This method is used to ensure that the event type
        //! @see fzEventType
        bool isType(fzEventType type) const {
            return !!(m_type & type);
        }
        
        
        //! Returns the event state.
        //! @see fzEventState
        fzEventState getState() const {
            return m_state;
        }
        
        
        //! 2D vector.
        //! Used as position in screen
        //! Normalized vector in a stick
        //! @see getVector()
        //! @see getScalar()
        fzPoint getPoint() const {
            return fzPoint(m_x, m_y);
        }
        
        
        //! 3D vector
        //! Used by the accelerometer events
        //! @see getPoint()
        //! @see getScalar()
        fzPoint3 getVector() const {
            return fzPoint3(m_x, m_y, m_z);
        }
        
        fzPoint3Double getVectorDouble() const {
            return fzPoint3Double(m_x, m_y, m_z);
        }
        
        
        //! Scalar value
        //! Used as button preasure, for example in Playstation
        //! @see getPoint()
        //! @see getVector()
        fzFloat getScalar() const {
            return m_z;
        }
        
        
        //! Returns the life cycle of the events measured in seconds
        fzFloat getElapsed() const {
            time_t now; time(&now);
            return difftime(now, m_creation);
        }
        
        
        //! Returns the event's delegate
        EventDelegate* getDelegate() const {
            return p_delegate;
        }
        
        
        //! Returns the event's identifier.
        //! Identifier = key pressed.
        //! @see kFZEventType_Key
        intptr_t getIdentifier() const {
            return m_identifier;
        }
      
      
        void *getOwner() const {
          return p_owner;
        }
        
        
        //! Sets user data
        //! Useful user configured value to design integrate the events with your games.
        //! @see getUserData()
        void setUserData(void *data) {
            p_userData = data;
        }
        
        
        //! Gets user data
        //! @see setUserData()
        void *getUserData() const {
            return p_userData;
        }

        
        //! Prints a log with the whole event info.
        void log() const;
    };
}
#endif