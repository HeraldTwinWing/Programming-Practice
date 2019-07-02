#pragma once
#include <SDL.h>
#include "Character.h"
#include "RestartButton.h"

/** 处理游戏的输入事件(键盘、鼠标)
 */
class GameEvent
{
public:
    GameEvent() = default;

    virtual ~GameEvent();

    virtual void OnEvent(SDL_Event& Event);

    virtual void OnInputFocus();

    virtual void OnInputBlur();

    virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod);

    virtual void OnKeyUp(SDL_Keycode sym, Uint16 mod);

    virtual void OnMouseFocus();

    virtual void OnMouseBlur();

    virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);

    virtual void OnMouseWheel(bool Up, bool Down);

    virtual void OnLButtonDown(int mX, int mY);

    virtual void OnLButtonUp(int mX, int mY);

    virtual void OnRButtonDown(int mX, int mY);

    virtual void OnRButtonUp(int mX, int mY);

    virtual void OnMButtonDown(int mX, int mY);

    virtual void OnMButtonUp(int mX, int mY);

    virtual void OnJoyAxis(SDL_JoystickID which, Uint8 axis, Sint16 value);

    virtual void OnJoyButtonDown(SDL_JoystickID which, Uint8 button);

    virtual void OnJoyButtonUp(SDL_JoystickID which, Uint8 button);

    virtual void OnJoyHat(SDL_JoystickID which, Uint8 hat, Uint8 value);

    virtual void OnJoyBall(SDL_JoystickID which, Uint8 ball, Sint16 xrel, Sint16 yrel);

    virtual void OnExpose();

    virtual void OnExit();

    virtual void OnUser(Uint32 type, int code, void* data1, void* data2);

};

extern GameEvent* eventHandler;
