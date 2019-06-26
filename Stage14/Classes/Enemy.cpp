
#include "Enemy.h"


Enemy::Enemy(Updater* updater, float X, float Y)
  : Updatable(updater)
{
  enemy = Sprite::create("Skeleton/Skeleton.png");
  enemy->setPosition(Vec2(X, Y));
  enemy->setScale(3);
  enemy->setAnchorPoint(Vec2(0.5, 0.5));

}

void Enemy::MoveAt(float X, float Y)
{
  if (X < 0)
    enemy->setFlippedX(true);
  else
    enemy->setFlippedX(false);

  auto moveBy = MoveBy::create(0.01667f, Vec2(X, Y));
  enemy->runAction(moveBy);
}

void Enemy::Update(float delta)
{
  // do nothing right now
}
