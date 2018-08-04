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

        inline std::string& getText(){
            return this->text;
        }

        inline void setText(std::string text){
            this->text = text;
        }

        inline int32_t Color(){
            return color;
        }

        inline int getMaxLines(){
            return this->maxLines;
        }

        inline void setMaxLines(int maxLines){
            this->maxLines = maxLines;
        }

        inline void setColor(int32_t color){
            this->color = color;
        }

        inline int32_t FontSize(){
            return fontSize;
        }

        inline void setFontSize(int32_t fontSize){
            this->fontSize = fontSize;
        }

        inline void setLineHeight(int lineHeight){
            this->lineHeight = lineHeight;
        }

        inline int getLineHeight(){
            return this->lineHeight;
        }

        inline void setTextOverflow(TextOverflow overflow){
            this->overflow = overflow;
        }

        inline TextOverflow  getOverflow(){
            return this->overflow;
        }

        inline void setAlignment(Alignment alignment){
            this->alignment = alignment;
        }

        inline Alignment getAlignment(){
            return this->alignment;
        }

        inline void setDecoration(TextDecoration decoration){
            this->decoration = decoration;
        }

        inline TextDecoration getDecoration(){
            return this->decoration;
        }





    private:
        int32_t  color;
        int32_t fontSize;
        int lineHeight;
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
                printf("paint->measureText0 %d \n", width);
                return  width;
            }
            if((line + 1) < maxLines){
                printf("paint->measureText1 %d \n", width);
                return  width;
            }
            printf("paint->measureText");
            return  width - paint->measureText("...", 0, 3);
        }
    };

}



#endif //RENDERUI_TEXT_H
