
#include "Hero.h"

Hero::Hero(KeyboardListener* aKeyboardListener, HealthBar* aHealthBar, KeyControls aKeyControls, Updater* updater)
  : Character(updater)
{
  keyboardListener = aKeyboardListener;
  healthBar = aHealthBar;
  keyControls = aKeyControls;

  // init hero
  characterSprite = Sprite::create("MinotaurFirst.png");

  auto X = Director::getInstance()->getVisibleSize().width / 2;
  auto Y = Director::getInstance()->getVisibleSize().height / 2;

  characterSprite->setPosition(Vec2(X, Y));
  characterSprite->setScale(3);
  characterSprite->setAnchorPoint(Vec2(0.5, 0.5));
}

Sprite* Hero::GetSprite()
{
  return characterSprite;
}

void Hero::Move(float delta)
{
  int direction = GetMoveDirection();

  auto direction2D = Vec2(0, 0);
  float X = characterSprite->getPositionX();
  float Y = characterSprite->getPositionY();

  if (direction == LEFT)
    characterSprite->setFlippedX(true);
  if (direction == RIGHT)
    characterSprite->setFlippedX(false);

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
  characterSprite->runAction(moveBy);
}

void Hero::TakeDamage(int damage)
{
  health -= damage;
  health = max(0, health);

  healthBar->UpdateHealth(health);
}

int Hero::GetMoveDirection()
{
  if (keyboardListener->IsKeyPressed(keyControls.LeftKey))
    return LEFT;

  if (keyboardListener->IsKeyPressed(keyControls.RightKey))
    return RIGHT;

  if (keyboardListener->IsKeyPressed(keyControls.UpKey))
    return UP;

  if (keyboardListener->IsKeyPressed(keyControls.DownKey))
    return DOWN;

  return NODIRECTION;
}

void Hero::Update(float delta)
{
  Move(delta);
}
