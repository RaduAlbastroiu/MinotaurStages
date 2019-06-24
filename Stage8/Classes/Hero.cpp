
#include "Hero.h"

Hero::Hero(KeyboardListener* aKeyboardListener)
{
  keyboardListener = aKeyboardListener;

  // init hero
  hero = Sprite::create("MinotaurFirst.png");

  auto X = Director::getInstance()->getVisibleSize().width / 2;
  auto Y = Director::getInstance()->getVisibleSize().height / 2;

  hero->setPosition(Vec2(X, Y));
  hero->setScale(3);
  hero->setAnchorPoint(Vec2(0.5, 0.5));
}

Sprite* Hero::GetSprite()
{
  return hero;
}

void Hero::Move(float delta)
{
  int direction = keyboardListener->GetMoveDirection();

  auto direction2D = Vec2(0, 0);
  float X = hero->getPositionX();
  float Y = hero->getPositionY();

  if (direction == LEFT)
    hero->setFlippedX(true);
  if (direction == RIGHT)
    hero->setFlippedX(false);

  switch (direction)
  {
  case LEFT:
    direction2D = Vec2(-1 * speed, 0);
    X += -1 * speed;
    break;

  case RIGHT:
    direction2D = Vec2(1 * speed, 0);
    X += speed;
    break;

  case UP:
    direction2D = Vec2(0, 1 * speed);
    Y += speed;
    break;

  case DOWN:
    direction2D = Vec2(0, -1 * speed);
    Y -= speed;
    break;
  }

  auto moveBy = MoveBy::create(delta, direction2D);
  hero->runAction(moveBy);
}

void Hero::Update(float delta)
{
  Move(delta);
}
