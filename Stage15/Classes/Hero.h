#pragma once

#include "Includes.h"
#include "KeyboardListener.h"
#include "HealthBar.h"
#include "Character.h"

class Hero : public Character
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

  KeyboardListener* keyboardListener;
  KeyControls keyControls;
  HealthBar* healthBar;
};
