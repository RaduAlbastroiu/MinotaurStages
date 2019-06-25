#pragma once

#include "Includes.h"

class IUpdatable
{
public: 
  virtual void Update(float delta) = 0;
};
