//
// Created by furture on 2018/5/30.
//

#include "Div.h"

namespace RenderUI{

    Div::Div() {
        childs = new ChildList();
        tag = "div";
    }

    void Div::layout() {
        for(auto it = childs->begin(); it != childs->end(); it++){
            printf("text layout  %p %d\n", *it, *it == nullptr);
            (*it)->layout();
        }
    }

    void Div::draw(Canvas *canvas) {
        drawBackground(canvas);
        drawContent(canvas);
        for(auto it = childs->begin(); it != childs->end(); it++){
            Div* child = *it;
            Rect rect = child->Frame();
            canvas->tranlate(rect.x, rect.y);
            (*it)->draw(canvas);
            canvas->tranlate(-rect.x, -rect.y);
        }
        drawForeground(canvas);
    }

    void Div::drawBackground(Canvas *canvas) {
        if(backgroundColor != 0){
            Rect rect = Frame();
            canvas->drawRect(rect, nullptr);
        }
    }

    void Div::drawContent(Canvas *canvas) {

    }

    void Div::drawForeground(Canvas *canvas) {

    }




    void Div::addChild(Div *div) {
        childs->push_back(div);
    }

    void Div::addRemove(Div* div){
        std::remove(childs->begin(), childs->end(), div);
    }

    Div::~Div() {
        if(childs != nullptr){
            for(auto it = childs->begin(); it != childs->end(); it++){
                Div* child = *it;
                delete  child;
                child = nullptr;
            }
            delete  childs;
            childs = nullptr;
        }
    }
}

