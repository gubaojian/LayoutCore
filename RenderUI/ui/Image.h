//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_IMAGE_H
#define RENDERUI_IMAGE_H
#include "Div.h"

namespace RenderUI{
    class Image : public Div {


    public:
        void drawContent(Canvas* canvas) override;

        inline std::string& Src(){
            return src;
        }
        inline void setSrc(std::string src){
            this->src = src;
        }

    private:
        std::string src;


    };
}


#endif //RENDERUI_IMAGE_H
