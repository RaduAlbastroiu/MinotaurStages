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
  

  void TakeDamage(int damage);

private:

  void Update(float delta) override;

  void Attack() override;
  void Move(float delta);

  bool CanMoveAt(float currentX, float currentY, float X, float Y);
  int GetMoveDirection();

  void RunAnimation(vector<string>& aAnimSprites, int aNrRuns, float aFrecv);

  // Inherited via Character
  virtual void RunAttackAnimation() override;

  virtual void RunIdleAnimation() override;

  virtual void RunMoveAnimation() override;

  virtual void RunHitAnimation() override;

  virtual void RunDeadAnimation() override;


  int speed = 10;

  KeyboardListener* keyboardListener;
  KeyControls keyControls;
  HealthBar* healthBar;

  vector<string> mHeroAttack = { "MinotaurAttack_0.png",
 "MinotaurAttack_1.png" ,
 "MinotaurAttack_2.png" ,
 "MinotaurAttack_3.png" ,
 "MinotaurAttack_4.png" ,
 "MinotaurAttack_5.png" ,
 "MinotaurAttack_6.png" ,
 "MinotaurAttack_7.png" ,
 "MinotaurAttack_8.png" };

  vector<string> mHeroIdle = { "MinotaurIdle_0.png",
  "MinotaurIdle_1.png" ,
  "MinotaurIdle_2.png" ,
  "MinotaurIdle_3.png" ,
  "MinotaurIdle_4.png" };

  vector<string> mHeroDead = { "MinotaurDead_0.png",
  "MinotaurDead_1.png" ,
  "MinotaurDead_2.png" ,
  "MinotaurDead_3.png" ,
  "MinotaurDead_4.png" ,
  "MinotaurDead_5.png" };

  vector<string> mHeroMove = { "MinotaurMove_0.png",
  "MinotaurMove_1.png" ,
  "MinotaurMove_2.png" ,
  "MinotaurMove_3.png" ,
  "MinotaurMove_4.png" ,
  "MinotaurMove_5.png" ,
  "MinotaurMove_6.png" ,
  "MinotaurMove_7.png" };
};
