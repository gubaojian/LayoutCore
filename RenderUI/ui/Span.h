//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_SPAN_H
#define RENDERUI_SPAN_H
#include "Div.h"
#include "TextLine.h"


namespace  RenderUI {

    class Span  : public Div{

    public:
        Span();
        ~Span();
        void layout() override;
        void draw(Canvas* canvas) override;

        inline Rect getFirstLineFrame(){
            Rect frame = Frame();
            if(lines.size() > 0){
                TextLine line = lines.at(0);
                frame.x = frame.x + line.getXOffset();
                frame.width = frame.width - line.getXOffset();
                frame.height = line.getLineHeight();
            }
            return frame;
        }

        inline Rect getLastLineFrame(){
            Rect frame = Frame();
            if(lines.size() > 0){
                TextLine line = lines.at(lines.size() -1);
                frame.width = frame.width - line.getSpace();
                frame.height = line.getLineHeight();
            }
            return frame;
        }


        inline void setXOffset(int xOffset){
            this->xOffset = xOffset;
        }

        inline int getXOffset(int xOffset){

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
        int xOffset;
        int yOffset;

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

#endif //RENDERUI_SPAN_H
