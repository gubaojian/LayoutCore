//
// Created by furture on 2018/5/30.
//

#include "Paint.h"


namespace RenderUI {


    Paint::Paint() {

    }

    void  Paint::setStyle(int32_t color) {

    }

    void Paint::setColor(int32_t color) {

    }

    void Paint::setFontSize(int32_t fontSize) {

    }

    void Paint::setFont(Font *font) {

    }

    int Paint::measureText(const char* text, int offset, int length) {
        std::string str(text);
        printf("measure text %s  %d %d \n", str.substr(offset, length).c_str(), offset, length);
        return 14*length;
    }

    FontMetrics Paint::getFontMetrics() {
        FontMetrics metrics;
        metrics.top = 10;
        metrics.height = 32;
        return metrics;
    }


}
