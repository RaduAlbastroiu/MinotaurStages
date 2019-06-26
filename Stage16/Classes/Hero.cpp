
#include "Hero.h"

Hero::Hero(KeyboardListener* aKeyboardListener, HealthBar* aHealthBar, KeyControls aKeyControls, Updater* updater)
  : Character(updater)
{
  keyboardListener = aKeyboardListener;
  healthBar = aHealthBar;
  keyControls = aKeyControls;

  // init hero
  SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Minotaur.plist");

  characterSprite = Sprite::create("MinotaurFirst.png");

  auto X = Director::getInstance()->getVisibleSize().width / 2;
  auto Y = Director::getInstance()->getVisibleSize().height / 2;

  characterSprite->setPosition(Vec2(X, Y));
  characterSprite->setScale(3);
  characterSprite->setAnchorPoint(Vec2(0.5, 0.5));

  RunAnimation(mHeroIdle, 1000, 0.15f);
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

  if (CanMoveAt(characterSprite->getPositionX(), characterSprite->getPositionY(), X, Y))
  {
    auto moveBy = MoveBy::create(delta, direction2D);
    characterSprite->runAction(moveBy);
  }
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

void Hero::RunAnimation(vector<string>& aAnimSprites, int aNrRuns, float aFrecv)
{
  auto spritecache = SpriteFrameCache::getInstance();
  Vector<SpriteFrame*> anim;
  for (int i = 0; i < aAnimSprites.size(); i++)
  {
    anim.pushBack(spritecache->getSpriteFrameByName(aAnimSprites[i]));
  }
  auto animation = Animation::createWithSpriteFrames(anim, aFrecv);
  cocos2d::Action* action = Repeat::create(Animate::create(animation), aNrRuns);
  lastAction = action;
  characterSprite->runAction(action);
}

void Hero::Update(float delta)
{
  // check for attack
  if (currentState != internalState::dead)
  {
    if (keyboardListener->IsKeyPressed(keyControls.AttackKey))
      Attack();
  }

  // change position relative to framerate
  if (currentState == internalState::move)
  {
    Move(delta);
  }

  // change between walking and idling
  if (GetMoveDirection() != NODIRECTION && currentState == internalState::idle)
  {
    ChangeState(internalState::move);
  }

  if (GetMoveDirection() == NODIRECTION && currentState == internalState::move)
  {
    ChangeState(internalState::idle);
  }

  // change between attack and idle
  if (currentState == internalState::attack && timePassed - timeAttackStart > 0.5f)
  {
    ChangeState(internalState::idle);
  }

  // update health 
  if (health <= 0 && currentState != internalState::dead)
  {
    ChangeState(internalState::dead);
  }

  // after hit go back to idle
  if (currentState == internalState::hit && timePassed - timeHitStart < 0.5f)
  {
    ChangeState(internalState::idle);
  }
}

void Hero::Attack()
{
  if (currentState != internalState::attack)
  {
    timeAttackStart = timePassed;
    //mEnemiesCollection->AttackCollection();
    ChangeState(internalState::attack);
  }
}


bool Hero::CanMoveAt(float currentX, float currentY, float X, float Y)
{
  const auto width = Director::getInstance()->getVisibleSize().width;
  const auto height = Director::getInstance()->getVisibleSize().height;

  // left margin
  if (X < currentX && X < 25)
  {
    return false;
  }
  // right margin
  if (X > currentX && X > width - 25)
  {
    return false;
  }
  // top
  if (Y > currentY && Y > height - 25)
  {
    return false;
  }
  // bottom
  if (Y < currentY && Y < 25)
  {
    return false;
  }

  return true;
}

void Hero::RunAttackAnimation()
{
  RunAnimation(mHeroAttack, 1, 0.045f);
}

void Hero::RunIdleAnimation()
{
  RunAnimation(mHeroIdle, 1000, 0.15f);
}

void Hero::RunMoveAnimation()
{
  RunAnimation(mHeroMove, 1000, 0.065f);
}

void Hero::RunHitAnimation()
{
}

void Hero::RunDeadAnimation()
{
  RunAnimation(mHeroDead, 1, 0.1f);
}
