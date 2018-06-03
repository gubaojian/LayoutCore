//
// Created by furture on 2018/5/30.
//

#include "Image.h"

namespace RenderUI{

    void Image::drawContent(Canvas* canvas) {
        Rect frame = this->Frame();
        canvas->drawImg(src, 0, frame.x, frame.y, frame.width, frame.height);
    }

}
