//
// Created by furture on 2018/5/30.
//

#ifndef RENDERUI_RICHTEXT_H
#define RENDERUI_RICHTEXT_H

namespace  RenderUI{

    class RichText: public Div {
    public:
        explicit RichText();
        void layout() override;
        void setText(std::string text);


    private:
        std::string text;
    };
}


#endif //RENDERUI_RICHTEXT_H
