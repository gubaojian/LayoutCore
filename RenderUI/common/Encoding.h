//
// Created by furture on 2018/6/1.
//

#ifndef RENDERUI_ENCODING_H
#define RENDERUI_ENCODING_H
#include <unitypes.h>
#include <set>


namespace RenderUI {

    namespace Encoding{

        /**
         * helloworld 3.333333
         * */
        static std::set<uint32_t> breakCodePoints = {':', ' ', '=', ','};



        bool isBreak(uint32_t codePoint);
        /***
         * return codePoint length, put codePoint value in codePoint
         * */
        short next_utf32_code_point_len(const char* utf8, int offset, int end, uint32_t* codePoint);
    };
}


#endif //RENDERUI_ENCODING_H
