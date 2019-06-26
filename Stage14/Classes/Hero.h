#pragma once

#include "Includes.h"
#include "KeyboardListener.h"
#include "HealthBar.h"
#include "Updatable.h"

class Hero : public Updatable
{
public:
  Hero(KeyboardListener* aKeyboardListener, HealthBar* aHealthBar, KeyControls aKeyControls, Updater* updater);
  Sprite* GetSprite();
  
  void Move(float delta);
  void TakeDamage(int damage);

  void Update(float delta) override;

private:

  int GetMoveDirection();

  int speed = 10;
  int health = 100;

  cocos2d::Sprite* hero;

  KeyboardListener* keyboardListener;
  KeyControls keyControls;
  HealthBar* healthBar;
};
