#pragma once

#include "Includes.h"

class IUpdatable;

class Updater : cocos2d::Node
{
public:

  void RegisterUpdatable(IUpdatable* updateable);
  void UnregisterUpdatable(IUpdatable* updateable);

  void UpdateAll(float delta);

private:
  set<IUpdatable*> toUpdate;
};
