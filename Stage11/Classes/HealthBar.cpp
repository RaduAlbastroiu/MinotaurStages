
#include "HealthBar.h"

HealthBar::HealthBar()
{
  healthSprite = cocos2d::Sprite::create("LifeBar/100.png");
  healthSprite->setScale(0.4f);
  healthSprite->setPosition(Director::getInstance()->getVisibleSize().width / 9, Director::getInstance()->getVisibleSize().height / 1.07);
}

Sprite* HealthBar::GetSprite()
{
  return healthSprite;
}

void HealthBar::UpdateHealth(int health)
{
  healthSprite->setTexture(mLifeBar[health / 10]);
}
