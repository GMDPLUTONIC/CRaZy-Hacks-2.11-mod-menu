#include "infoLayer.hpp"

InfoLayer* InfoLayer::create() {
    auto pRet = new InfoLayer();
    if (pRet && pRet->init()) {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

bool InfoLayer::init() {
    auto label = CCLabelBMFont::create("CRaZy HaX PRO Info", "goldFont.fnt");

    label->setPosition({270, 225});

    addChild(label);

    auto backgroundSprite = CCSprite::create("GJ_gradientBG.png");
    
    auto winSize = CCDirector::sharedDirector()->getWinSize();
    auto size = backgroundSprite->getContentSize();
    
    backgroundSprite->setScaleX(winSize.width / size.width);
    backgroundSprite->setScaleY(winSize.height / size.height);
    
    backgroundSprite->setAnchorPoint({0, 0});
    
    backgroundSprite->setColor({100, 100, 100});
    
    backgroundSprite->setZOrder(-1);
    addChild(backgroundSprite);

    auto button = gd::CCMenuItemSpriteExtra::create(
        CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
        this,
        menu_selector(InfoLayer::backButton)
    );

    auto menu = CCMenu::create();
    menu->addChild(button);
    menu->setPosition({25, winSize.height - 25});

    addChild(menu);

    setKeypadEnabled(true);

    return true;
}

void InfoLayer::callback(CCObject*) {
    auto scene = CCScene::create();
    auto InfoLayer = InfoLayer::create();
    scene->addChild(InfoLayer);
    CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, scene));
}

void InfoLayer::keybackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
}

void InfoLayer::backButton(CCObject* object) {
    keybackClicked();
}