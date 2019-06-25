
#include "KeyboardListener.h"


KeyboardListener::KeyboardListener()
{
  listener = EventListenerKeyboard::create();

  listener->onKeyPressed = [&](cocos2d::EventKeyboard::KeyCode keycode, Event* event) {
    keyboard[keycode] = true;
  };

  listener->onKeyReleased = [&](cocos2d::EventKeyboard::KeyCode keycode, Event* event) {
    keyboard.erase(keycode);
  };
}

EventListenerKeyboard* KeyboardListener::GetListener()
{
  return listener;
}

bool KeyboardListener::IsKeyPressed(EventKeyboard::KeyCode aKey)
{
  if (keyboard.find(aKey) != keyboard.end())
  {
    return true;
  }

  return false;
}
