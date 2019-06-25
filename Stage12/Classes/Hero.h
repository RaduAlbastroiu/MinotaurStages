#pragma once

#include "Includes.h"
#include "KeyboardListener.h"
#include "HealthBar.h"
#include "IUpdatable.h"

class Hero : public IUpdatable
{
public:
  Hero(KeyboardListener* aKeyboardListener, HealthBar* aHealthBar, KeyControls aKeyControls);
  Sprite* GetSprite();
  
  void Move(float delta);
  void TakeDamage(int damage);

  void Update(float delta);

private:

  int GetMoveDirection();

  int speed = 10;
  int health = 100;

  cocos2d::Sprite* hero;

  KeyboardListener* keyboardListener;
  KeyControls keyControls;
  HealthBar* healthBar;
};
