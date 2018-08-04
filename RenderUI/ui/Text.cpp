//
// Created by furture on 2018/5/31.
//

#include <sys/param.h>
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
          int width = frame.width;
          if(width <= 0){
              width = INT_MAX;
          }
          printf("wordWidth %d \n", width);
          int calcLineHeight = MAX(metrics.height, lineHeight);
          TextLine line(maxLineWidth(width, 0));
          line.setLineHeight(calcLineHeight);
          printf("wordWidth %d \n", maxLineWidth(width, 0));
          int offset = 0;
          int end = text.length();
          const char* utf8 = text.c_str();
          while(offset < end){
              uint32_t  codePoint = 0;
              int codePointBytesLen = RenderUI::Encoding::next_utf32_code_point_len(utf8, offset, end, &codePoint);
              int wordBytesLen = codePointBytesLen;
              printf("offset end start %d %d  %d \n", offset, end, RenderUI::Encoding::isBreak(codePoint));
              while(!RenderUI::Encoding::isBreak(codePoint) && (offset + wordBytesLen) < end){
                  printf("offset end2 %d  worldlen %d  %d  %c \n", offset, wordBytesLen, codePoint);
                  codePointBytesLen = RenderUI::Encoding::next_utf32_code_point_len(utf8, (offset + wordBytesLen), end, &codePoint);
                  printf("code len %d \n", codePointBytesLen);
                  wordBytesLen += codePointBytesLen;
              }
              //work break point should measure as single world
              if(wordBytesLen != codePointBytesLen){
                   wordBytesLen -= codePointBytesLen;
              }

              int wordWidth = paint->measureText(utf8, offset, wordBytesLen);
              printf("wordWidth append %d width %d  %d   %s \n", wordBytesLen, wordWidth, width, text.substr(offset, wordBytesLen).c_str());
              if(line.hasSpace(wordWidth)){
                  line.lineText().append(utf8, offset, wordBytesLen);
                  line.reduceSpace(wordWidth);
                  offset += wordBytesLen;
                  printf("wordWidth append next world %s \n", line.lineText().c_str());
                  continue;
              }

              printf("wordWidth append none space \n");

              if((lines.size() + 1) < maxLines){
                  lines.push_back(line);
                  line = TextLine(maxLineWidth(width, lines.size()));
                  line.setLineHeight(calcLineHeight);
                  line.lineText().append(utf8, offset, wordBytesLen);
                  line.reduceSpace(wordWidth);
                  offset += wordBytesLen;
                  continue;
              }
              break;
          }

          /**
           * append ellipsis if overflow ellipsis
           * */
          if(overflow == TextOverflow::OVERFLOW_ELLIPSIS){
              line.lineText().append(OVERFLOW_ELLIPSIS_STR);
              line.reduceSpace(paint->measureText("...", 0, 3));
          }

          if(lines.size() <= 0 || &lines.at(lines.size()-1) != &line){
              lines.push_back(line);
          }
      }


      void Text::drawContent(Canvas* canvas){
            printf("text draw content  %d \n", lines.size());
            Div::drawContent(canvas);
            Rect frame = Frame();
            int y = frame.y;
            int x = frame.x;
            for(auto line : lines){
                printf("text draw line %s  x %d y %d  height %d  space %d width %d\n", line.lineText().c_str(), x, y, line.getLineHeight(), line.getSpace(),
                frame.width);
                if(alignment == ALIGN_CENTER){
                    canvas->drawText(x + line.getSpace()/2, y + line.getLineHeight(), line.lineText(), 0, line.lineText().length(), paint);
                }else if(alignment == ALIGN_RIGHT){
                    //canvas->drawText(x, y + line.getLineHeight(), line.lineText(), 0, line.lineText().length(), paint);
                }else{
                   // canvas->drawText(x, y + line.getLineHeight(), line.lineText(), 0, line.lineText().length(), paint);
                }
                //line.lineText();
               // canvas->drawText(line.lineText(), 0, line.lineText().length(), paint);
                y += line.getLineHeight();
            }
      }



}