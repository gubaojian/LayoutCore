//
// Created by furture on 2018/5/30.
//

#include "Paint.h"


namespace RenderUI {

    void  Paint::setStyle(int32_t color) {

    }

    void Paint::setColor(int32_t color) {

    }

    void Paint::setFontSize(int32_t fontSize) {

    }

    void Paint::setFont(Font *font) {

    }

    int Paint::measureText(const char* text, int offset, int length) {
        return 32*length;
    }

    FontMetrics Paint::getFontMetrics() {
        FontMetrics metrics;
        metrics.top = 10;
        return metrics;
    }


}
