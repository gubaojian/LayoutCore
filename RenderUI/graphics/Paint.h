//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_PAINT_H
#define RENDERUI_PAINT_H

#include <unitypes.h>
#include "Font.h"

namespace RenderUI {

    enum Style{
        FILL,
        STOKE
    };

    class Paint {

    public:
        int measureText(const char* utf8, int offset, int length);
        void setColor(int32_t color);
        void setFontSize(int32_t fontSize);
        void setStyle(int32_t color);
        void setFont(Font* font);
        FontMetrics getFontMetrics();

    };
}



#endif //RENDERUI_PAINT_H
