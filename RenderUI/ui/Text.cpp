//
// Created by furture on 2018/5/31.
//

#include "Text.h"
#include "Encoding.h"


namespace  RenderUI{

      Text::Text() {

      }

      Text::~Text() {
          lines.clear();
      }

      void Text::layout() {
          if(paint == nullptr){
              paint = new Paint();
          }
          if(font.get() == nullptr){
              font = Font::getFont(fontFamily, fontStyle, fontWeight);
          }
          paint->setColor(color);
          paint->setFontSize(fontSize);
          paint->setFont(font.get());
          FontMetrics metrics = paint->getFontMetrics();
          lines.clear();

          Rect frame = this->Frame();
          float width = frame.width;
          if(width <= 0){
              width = INT_MAX;
          }
          TextLine line(maxLineWidth(width, 0));
          int offset = 0;
          int end = text.length();
          int wordLen = 0;
          const char* utf8 = text.c_str();
          while(offset < end){

              uint32_t  codePoint = 0;
              int codeLen = RenderUI::Encoding::next_utf32_code_point_len(utf8, offset, end, &codePoint);
              wordLen += codeLen;
              while(!RenderUI::Encoding::isBreak(codePoint) && (offset + wordLen) < end){
                  int codeLen = RenderUI::Encoding::next_utf32_code_point_len(utf8, (offset + wordLen), end, &codePoint);
                  wordLen += codeLen;
              }

              int wordWidth = paint->measureText(utf8, offset, wordLen);
              if(line.hasSpace(wordWidth)){
                  line.lineText().append(utf8, offset, wordLen);
                  offset += wordLen;
                  continue;
              }

              if((lines.size() + 1) < maxLines){
                  lines.push_back(line);
                  line = TextLine(maxLineWidth(width, lines.size()));
                  continue;
              }
              break;
          }

          /**
           * append ellipsis if overflow ellipsis
           * */
          if(overflow == TextOverflow::OVERFLOW_ELLIPSIS){
              line.lineText().append(OVERFLOW_ELLIPSIS_STR);
              lines.push_back(line);
          }
      }


      void Text::drawContent(Canvas* canvas){
            Div::drawContent(canvas);
            for(auto line : lines){
                line.lineText();
               // canvas->drawText(line.lineText(), 0, line.lineText().length(), paint);
            }
      }



}