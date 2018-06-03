//
// Created by furture on 2018/5/30.
//

#include "Font.h"
#include <memory>


namespace RenderUI {

    Font::Font(std::string fontFamily, FontStyle fontStyle, int32_t fontWeight) {
        this->fontFamily = fontFamily;
        this->fontStyle = fontStyle;
        this->fontWeight = fontWeight;
    }


    std::shared_ptr<Font> Font::getFont(std::string fontFamily, FontStyle fontStyle, int32_t fontWeight) {
        return std::make_shared<Font>(fontFamily, fontStyle, fontWeight);
    }
}
