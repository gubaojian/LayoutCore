//
// Created by furture on 2018/5/31.
//

#ifndef RENDERUI_TEXT_H
#define RENDERUI_TEXT_H
#include "Div.h"
#include "TextLine.h"


namespace  RenderUI{


    class Text : public Div {

    public:
        Text();
        ~Text();

        void layout() override;
        void drawContent(Canvas* canvas) override ;

        inline int32_t Color(){
            return color;
        };

        inline void setColor(int32_t color){
            this->color = color;
        }

        inline int32_t FontSize(){
            return fontSize;
        }

        inline void setFontSize(int32_t fontSize){
            this->fontSize = fontSize;
        }


    private:
        int32_t  color;
        int32_t fontSize;
        int32_t lineHeight;
        int32_t fontWeight;
        int maxLines = 0;
        FontStyle  fontStyle;
        Alignment alignment;
        TextDecoration decoration;
        TextOverflow overflow;
        std::string text;
        std::string fontFamily;
        Paint* paint;
        std::shared_ptr<Font> font;
        std::vector<TextLine> lines;

        inline int maxLineWidth(int width, int line){
            if(overflow == TextOverflow::OVERFLOW_NONE){
                return  width;
            }
            if((line + 1) < maxLines){
                return  width;
            }
            return  width - paint->measureText("...", 0, 3);
        }
    };

}



#endif //RENDERUI_TEXT_H
