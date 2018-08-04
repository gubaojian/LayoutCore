//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_FONT_H
#define RENDERUI_FONT_H

#include <memory>
#include <string>

namespace RenderUI {


    enum FontWeight{
        WEIGHT_NORMAL,
        WEIGHT_BOLD,
        WEIGHT_BOLDER,
        WEIGHT_LIGHTER
    };
    enum FontStyle{
        STYLE_NORMAL,
        STYLE_ITALIC,
        STYLE_BOLD
    };
    enum Alignment{
        ALIGN_NORMAL,
        ALIGN_LEFT,
        ALIGN_CENTER,
        ALIGN_RIGHT,
    };

    enum TextDecoration{
        DECORATION_INVALID,
        DECORATION_NONE,
        DECORATION_UNDERLINE,
        DECORATION_LINETHROUGH
    };

    enum TextOverflow{
        OVERFLOW_NONE,
        OVERFLOW_ELLIPSIS
    };

    typedef  struct FontMetrics{
        int top;
        int ascent;
        int descent;
        int bottom;
        int leading;
        int height;
    } FontMetrics;


    class Font {


    public:
        Font(std::string fontFamily, FontStyle fontStyle, int32_t fontWeight);
        static std::shared_ptr<Font> getFont(std::string fontFamily, FontStyle fontStyle, int32_t fontWeight);


    private:
        std::string fontFamily;
        FontStyle fontStyle;
        int32_t fontWeight;
    };
}




#endif //RENDERUI_FONT_H
