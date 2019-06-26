
#include "Updatable.h"
#include "Updater.h"

Updatable::Updatable(Updater* updater)
  :updater(updater)
{
  updater->RegisterUpdatable(this);
}

Updatable::~Updatable()
{
  updater->UnregisterUpdatable(this);
}

void Updatable::DoUpdate(float delta)
{
  timePassed += delta;
  Update(delta);
}
