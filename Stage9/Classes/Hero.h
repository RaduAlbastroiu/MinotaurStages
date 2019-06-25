#pragma once

#include "Includes.h"
#include "KeyboardListener.h"
#include "HealthBar.h"

class Hero
{
public:
  Hero(KeyboardListener* aKeyboardListener, HealthBar* aHealthBar);
  Sprite* GetSprite();
  
  void Move(float delta);
  void TakeDamage(int damage);

  void Update(float delta);

private:

  int speed = 10;
  int health = 100;

  cocos2d::Sprite* hero;

  KeyboardListener* keyboardListener;
  HealthBar* healthBar;
};
