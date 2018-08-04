//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_DIV_H
#define RENDERUI_DIV_H

#include <vector>
#include "Canvas.h"
#include "geometry.h"


namespace RenderUI{

    const static std::string TAG_DIV = "div";
    const static std::string TAG_SPAN = "span";

    class Div;
    typedef std::vector<Div*> ChildList;
    typedef enum BorderStyle{
        STYLE_SOLID,
    }BorderStyle;

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
        ChildList* getChilds(){
            return childs;
        }

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

        inline void setBackgroundColor(int32_t  backgroundColor){
            this->backgroundColor = backgroundColor;
        }

        inline int32_t getBackgroundColor(){
            return this->backgroundColor;
        }

        inline void setTag(std::string tag){
            this->tag = tag;
        }

        inline std::string& getTag(){
            return this->tag;
        }



    private:
        Rect  frameRect;
        Margin margin;
        Padding padding;
        ChildList* childs;
        int32_t  backgroundColor;
        int borderRadius;
        BorderStyle borderStyle;
        int borderColor;
        int borderWidth;
        std::string tag;




    };
}



#endif //RENDERUI_DIV_H
