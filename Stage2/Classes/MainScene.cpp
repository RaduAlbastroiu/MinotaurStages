/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "MainScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
  // ini hero
  cocos2d::Sprite* hero = Sprite::create("MinotaurFirst.png");

  auto X = Director::getInstance()->getVisibleSize().width / 2;
  auto Y = Director::getInstance()->getVisibleSize().height / 2;

  hero->setPosition(Vec2(X, Y));
  hero->setScale(3);
  hero->setAnchorPoint(Vec2(0.5, 0.5));

  this->addChild(hero, 100);


  // init background
  for (int i = 0; i <= Director::getInstance()->getVisibleSize().width / 1024; i++)
  {
    for (int j = 0; j <= Director::getInstance()->getVisibleSize().height / 1024; j++)
    {
      cocos2d::Sprite* background = Sprite::create("grass.png");
      background->setAnchorPoint(Vec2(0, 0));
      background->setPosition(Vec2(1024 * i, 1024 * j));
      this->addChild(background, 0);
    }
  }


  // init health bar
  cocos2d::Sprite* healthBar = cocos2d::Sprite::create("LifeBar/100.png");
  healthBar->setScale(0.4f);
  healthBar->setPosition(Director::getInstance()->getVisibleSize().width / 9, Director::getInstance()->getVisibleSize().height / 1.07);
  this->addChild(healthBar);


  // init score label
  cocos2d::Label* scoreLabel = Label::createWithSystemFont("Killed: 0", "Arial", 50);
  scoreLabel->setPosition(Director::getInstance()->getVisibleSize().width / 10 * 9, Director::getInstance()->getVisibleSize().height / 1.07);
  scoreLabel->setTextColor(cocos2d::Color4B::BLACK);
  this->addChild(scoreLabel);

  return true;
}
