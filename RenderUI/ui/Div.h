//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_DIV_H
#define RENDERUI_DIV_H

#include <vector>
#include "Canvas.h"
#include "geometry.h"


namespace RenderUI{

    class Div;
    typedef std::vector<Div*> ChildList;

    class Div {



    public:
        Div();
        ~Div();

        virtual void layout();
        virtual void draw(Canvas* canvas);
        virtual void drawBackground(Canvas* canvas);
        virtual void drawContent(Canvas* canvas);
        virtual void drawForeground(Canvas* canvas);

        void prepareDraw();
        void invalidate();
        void requestInvalidate();


        void addChild(Div* div);
        void addRemove(Div* div);

        inline Rect Frame(){
            return this->frameRect;
        }

        inline void setFrame(Rect rect){
            this->frameRect = rect;
        }

        inline Margin margins(){
            return this->margin;
        }

        inline void setMargins(Margin margin){
            this->margin = margin;
        }

        inline Padding paddings(){
            return padding;
        }

        inline void setPaddings(Padding padding){
            this->padding = padding;
        }

    private:
        Rect  frameRect;
        Margin margin;
        Padding padding;
        ChildList* childs;



    };
}



#endif //RENDERUI_DIV_H
