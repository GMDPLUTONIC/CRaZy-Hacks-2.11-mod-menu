#pragma once
#include "../pch.h"

class InfoLayer : public CCLayer {
    protected:
        virtual bool init();
        virtual void keybackClicked();
        void backButton(CCObject*);
    public:
        static InfoLayer* create();
        void callback(CCObject*);
};