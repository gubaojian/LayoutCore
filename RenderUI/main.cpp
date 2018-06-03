#include <iostream>
#include "Div.h"
#include "Text.h"
#include "Encoding.h"

using namespace RenderUI;

int main() {

    int offset = 0;
    int end = 10;
    const char* utf8 = "";

    uint32_t  codePoint = 0;
    int codeLen = RenderUI::Encoding::next_utf32_code_point_len(utf8, offset, end, &codePoint);


    Div* div = new Div();
    Text* text = new Text();
    text->setFontSize(32);
    text->setColor(0x888888);
    div->addChild(text);
    Canvas* canvas = new Canvas("renderUi.png");
    Paint* paint = new Paint();

    std::string hello = "hello 中国";
    canvas->drawText(hello, 0, hello.length(), paint, 100, 100);

    std::cout << "layout done" << std::endl;
    div->layout();
    std::cout << "layout done" << std::endl;
    div->draw(canvas);

    std::cout << "Hello, World!" << std::endl;
    delete  canvas;

    return 0;
}