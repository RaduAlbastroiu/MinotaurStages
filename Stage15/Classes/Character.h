#pragma once

#include "cocos2d.h"
#include "Includes.h"
#include "Updatable.h"
#include "KeyboardListener.h"


class Character : public Updatable
{
public:
  Character(Updater* updater);
  virtual cocos2d::Sprite* GetSprite();

  virtual void TakeDamage(int damage);
  virtual bool IsAlive();


  virtual pair<float, float> GetPosition();

protected:

  cocos2d::Sprite* characterSprite;

  int health = 100;
};
