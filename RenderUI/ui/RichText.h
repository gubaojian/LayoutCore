//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_RICHTEXT_H
#define RENDERUI_RICHTEXT_H
#include "Text.h"

namespace  RenderUI{

    class RichText: public Div {
    public:
        explicit RichText();
        void layout() override;
        void draw(Canvas* canvas) override;
    };
}


#endif //RENDERUI_RICHTEXT_H
