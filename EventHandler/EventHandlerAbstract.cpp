#include "EventHandlerAbstract.h"
#include "../GameLoop/GameLoop.h"

EventHandlerAbstract::EventHandlerAbstract() {

}
EventHandlerAbstract::~EventHandlerAbstract(){

}

void EventHandlerAbstract::OnEvent(SDL_Event* Event)
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    switch(Event->type)
    {
    case SDL_MOUSEBUTTONDOWN:
    {
        int x, y;
        SDL_GetMouseState( &x, &y );
        OnMButtonDown(x, y);
    }
    case SDL_KEYDOWN:
    {
        OnKeyDown(currentKeyStates);
        break;
    }
    case SDL_KEYUP:
    {
        OnKeyUp(currentKeyStates);
        break;
    }
    case SDL_QUIT:
    {
        OnExit();
        break;
    }
    }
}


void EventHandlerAbstract::OnInputFocus() {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnInputBlur() {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnKeyDown(const Uint8* scancode) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnKeyUp(const Uint8* scancode) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnMouseFocus() {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnMouseBlur() {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnMouseWheel(bool Up, bool Down) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnLButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnLButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnRButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnRButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnMButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnMButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}
/*
void EventHandlerAbstract::OnJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnJoyButtonDown(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnJoyButtonUp(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
    //Pure virtual, do nothing
}
*/
void EventHandlerAbstract::OnMinimize() {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnRestore() {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnResize(int w,int h) {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnExpose() {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnExit() {
    //Pure virtual, do nothing
}

void EventHandlerAbstract::OnUser(Uint8 type, int code, void* data1, void* data2) {
    //Pure virtual, do nothing
}
