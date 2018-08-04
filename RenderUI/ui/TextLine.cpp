//
// Created by furture on 2018/5/31.
//

#include "TextLine.h"
namespace  RenderUI {

   TextLine::TextLine(int maxWidth) {
       printf("textLine max width %d \n", maxWidth);
      this->maxWidth = maxWidth;
      this->space = maxWidth;
   }
}