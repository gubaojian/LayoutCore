//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_GEOMETRY_H
#define RENDERUI_GEOMETRY_H

namespace RenderUI {

    typedef struct Rect{
        int x;
        int y;
        int width;
        int height;
    } Rect;

    typedef struct Size{
        int width;
        int height;
    } Size;

    typedef struct Margin{
        int left;
        int top;
        int right;
        int bottom;
    } Margin;

    typedef struct Padding{
        int left;
        int top;
        int right;
        int bottom;
    } Padding;


    static inline Rect MakeRect(int x, int y, int width, int height){
        Rect rect;
        rect.x = x;
        rect.y = y;
        rect.width = width;
        rect.height = height;
        return rect;
    }

}


#endif //RENDERUI_GEOMETRY_H
