//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_CANVAS_H
#define RENDERUI_CANVAS_H

#include <unitypes.h>
#include <string>
#include "Paint.h"

namespace RenderUI {

    class Canvas {

    public:
        Canvas(std::string config);
        ~Canvas();
        void drawText(std::string& text, int offset, int length, Paint* paint, float x, float y);
        void drawImg(std::string& src, int scaleType, float x, float y, float width, float height);

        void tranlate(float dx, float dy);

    private:
        std::string config;
        void* ptr;
        void* surface;
    };
}


#endif //RENDERUI_CANVAS_H
