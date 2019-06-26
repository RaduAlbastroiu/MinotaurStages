#pragma once

#include "cocos2d.h"
#include "Includes.h"
#include "Updatable.h"

class Enemy : public Updatable
{
public:
  Enemy(Updater* updater, float X, float Y);
  
  void MoveAt(float X, float Y);

  void Update(float delta);


private:

  cocos2d::Sprite* enemy;
};

