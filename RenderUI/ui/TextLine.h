//
// Created by furture on 2018/5/31.
//

#ifndef RENDERUI_TEXTLINE_H
#define RENDERUI_TEXTLINE_H


#include <string>
#include <geometry.h>
#include <Canvas.h>


#define OVERFLOW_ELLIPSIS_STR  "..."

namespace  RenderUI{

    class TextLine {

    public:
        TextLine(int maxWidth);

        inline std::string& lineText(){
            return text;
        }

        inline  bool hasSpace(int spaceWidth){
            return space >= spaceWidth;
        }



    private:
        int maxWidth;
        int space;
        std::string text;
        Rect frame;
    };
}



#endif //RENDERUI_TEXTLINE_H
