
#include "Updater.h"
#include "IUpdatable.h"


void Updater::RegisterUpdatable(IUpdatable* updateable)
{
  toUpdate.insert(updateable);
}

void Updater::UnregisterUpdatable(IUpdatable* updateable)
{
  toUpdate.erase(updateable);
}

void Updater::UpdateAll(float delta)
{
  for (auto updateable : toUpdate)
    updateable->Update(delta);
}
