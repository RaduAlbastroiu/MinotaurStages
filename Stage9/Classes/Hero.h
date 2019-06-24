#pragma once

#include "Includes.h"
#include "KeyboardListener.h"

class Hero
{
public:
  Hero(KeyboardListener* aKeyboardListener);
  Sprite* GetSprite();
  
  void Move(float delta);

  void Update(float delta);

private:

  int speed = 10;
  cocos2d::Sprite* hero;

  KeyboardListener* keyboardListener;

};
