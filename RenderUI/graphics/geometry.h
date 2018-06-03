//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_GEOMETRY_H
#define RENDERUI_GEOMETRY_H

namespace RenderUI {

    typedef struct Rect{
        float x;
        float y;
        float width;
        float height;
    } Rect;

    typedef struct Size{
        float width;
        float height;
    } Size;

    typedef struct Margin{
        float left;
        float top;
        float right;
        float bottom;
    } Margin;

    typedef struct Padding{
        float left;
        float top;
        float right;
        float bottom;
    } Padding;

}


#endif //RENDERUI_GEOMETRY_H
