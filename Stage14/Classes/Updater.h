#pragma once

#include "Includes.h"

class Updatable;

class Updater : cocos2d::Node
{
public:

  void RegisterUpdatable(Updatable* updateable);
  void UnregisterUpdatable(Updatable* updateable);

  void UpdateAll(float delta);

private:
  set<Updatable*> toUpdate;
};
