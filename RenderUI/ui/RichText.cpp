//
// Created by furture on 2018/5/30.
//

#include "RichText.h"
#include "Span.h"

namespace  RenderUI{

    void RichText::layout() {
        ChildList* childList = getChilds();
        Rect parentRect = Frame();
        int x = parentRect.x;
        int y = parentRect.y;
        for(auto it = childList->begin(); it != childList->end(); it++){
            Div* child = *it;
            Rect childFrame = Frame();
            childFrame.y = y;
            if(child->getTag() == TAG_SPAN){
                Span* span = dynamic_cast<Span *>(child);
                span->setFrame(childFrame);
                span->setXOffset(x);
                span->layout();
                Rect lastLineFrame = span->getLastLineFrame();
                x = lastLineFrame.x + lastLineFrame.width;
                y = lastLineFrame.y + lastLineFrame.height;
            }else{
                child->setFrame(childFrame);
            }
            child->layout();
        }
    }

    void RichText::draw(Canvas *canvas) {
        Div::drawBackground(canvas);
        ChildList* childList = getChilds();
        for(auto it = childList->begin(); it != childList->end(); it++){
            Div* child = *it;
            Rect rect = child->Frame();
            canvas->tranlate(rect.x, rect.y);
            (*it)->draw(canvas);
            canvas->tranlate(-rect.x, -rect.y);
        }
        Div::drawForeground(canvas);
    }
}