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

        inline int getXOffset(){
            return this->xOffset;
        }

        inline void setLineHeight(int lineHeight){
             this->lineHeight = lineHeight;
        }

        inline int getLineHeight(){
            return this->lineHeight;
        }

        inline std::string& lineText(){
            return text;
        }

        inline  bool hasSpace(int spaceWidth){
            return space >= spaceWidth;
        }

        inline int getSpace(){
            return this->space;
        }

        inline void reduceSpace(int spaceWidth){
            this->space -= spaceWidth;
        }

        inline int getMaxWidth(){
            return this->maxWidth;
        }


    private:
        int maxWidth;
        int space;
        std::string text;
        int lineHeight = 0 ;
        int  xOffset;
    };
}



#endif //RENDERUI_TEXTLINE_H
