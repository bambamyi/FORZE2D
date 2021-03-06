
#include "TestBase.h"

using namespace FORZE;

#pragma mark - TestScene

#define TEST_LAYER 2

#define TITLE_OFFSET 44
#define MESSAGE_OFFSET 70


TestScene::TestScene(TestLayer* (*func)(fzUInt), fzUInt number)
: p_function(func)
, m_nuLayers(number)
, m_currentLayer(0)
{
    p_title = new Label(NULL, "font_menu.fnt");
    p_title->setPosition(getContentSize().width/2, getContentSize().height-TITLE_OFFSET);
    
    p_message = new Label(NULL, "font_menu.fnt");
    p_message->setAnchorPoint(0.5, 1);
    p_message->setAlignment(kFZLabelAlignment_center);
    p_message->setPosition(getContentSize().width/2, getContentSize().height-MESSAGE_OFFSET);
    p_message->setScale(0.5f);
    

    // HUD
    MenuItem *prev = new MenuItemImage("menu_left.png", this, SEL_PTR(TestScene::prevLayer));
    MenuItem *reload = new MenuItemImage("menu_reset.png", this, SEL_PTR(TestScene::reloadLayer));
    MenuItem *next = new MenuItemImage("menu_right.png", this, SEL_PTR(TestScene::nextLayer));
    
    Menu *menu = new Menu(prev, reload, next, NULL);
    menu->setPosition(getContentSize().width/2, 50);
    menu->alignChildrenHorizontally(-12);
    menu->setName("Menu");
    
    
    addChild(menu, NODE_TOP);
    addChild(p_title, NODE_TOP);
    addChild(p_message, NODE_TOP);

    // LOAD FIRST TEST
    reloadLayer(NULL);
}

void TestScene::updateLayout()
{
    setContentSize(FZ_CANVAS_SIZE());
    
    p_title->setPosition(getContentSize().width/2, getContentSize().height-TITLE_OFFSET);
    p_message->setPosition(getContentSize().width/2, getContentSize().height-MESSAGE_OFFSET);
    getChildByName("Menu")->setPosition(getContentSize().width/2, 50);
    
    Node::updateLayout();
}


void TestScene::prevLayer(void*)
{
    --m_currentLayer;
    m_currentLayer = (m_currentLayer < 0) ? (m_nuLayers-1) : m_currentLayer;
    reloadLayer(NULL);    
}


void TestScene::reloadLayer(void*)
{
    removeChildByTag(TEST_LAYER);
    
    TestLayer *test = p_function(m_currentLayer);
    test->setTag(TEST_LAYER);
    addChild(test);
    
    p_title->setString(test->getTitle());
    p_message->setString(test->getMessage());
}


void TestScene::nextLayer(void*)
{
    ++m_currentLayer;
    m_currentLayer = (m_currentLayer >= m_nuLayers) ? 0 : m_currentLayer;
    reloadLayer(NULL);    
}



#pragma mark - TestLayer

TestLayer::TestLayer(const char* title, const char* message)
: p_title(NULL)
, p_message(NULL)
{
    p_title = fzStrcpy(title);
    p_message = fzStrcpy(message);

}

TestLayer::~TestLayer()
{
    delete p_title;
    delete p_message;
}
