//
// Created by furture on 2018/6/1.
//

#include "Encoding.h"


namespace RenderUI {

    namespace Encoding {
        /*
         * Index into the table below with the first byte of a UTF-8 sequence to
         * get the number of trailing bytes that are supposed to follow it.
         * Note that *legal* UTF-8 values can't have 4 or 5-bytes. The table is
         * left as-is for anyone who may want to do such conversion, which was
         * allowed in earlier algorithms.
         */
        static const char trailingBytesForUTF8[256] = {
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3,4,4,4,4,5,5,5,5
        };


        static const uint32_t offsetsFromUTF8[6] = { 0x00000000UL, 0x00003080UL, 0x000E2080UL,
                                                  0x03C82080UL, 0xFA082080UL, 0x82082080UL };

         bool isBreak(uint32_t codePoint){
             if(codePoint > 128){
                 return true;
             }
             auto it =  breakCodePoints.find(codePoint);
             return breakCodePoints.end() != it;
        }

        short next_utf32_code_point_len(const char* utf8, int offset, int end, uint32_t* codePoint){
            uint32_t  ch = 0;
            unsigned short extraBytesToRead = trailingBytesForUTF8[utf8[offset]];
            if (offset + extraBytesToRead >= end) {
                return  end - offset;
            }
            /*
             * The cases all fall through. See "Note A" below.
             */
            switch (extraBytesToRead) {
                case 5: ch += *utf8++; ch <<= 6;
                case 4: ch += *utf8++; ch <<= 6;
                case 3: ch += *utf8++; ch <<= 6;
                case 2: ch += *utf8++; ch <<= 6;
                case 1: ch += *utf8++; ch <<= 6;
                case 0: ch += *utf8++;
            }

            ch -= offsetsFromUTF8[extraBytesToRead];
            *codePoint = ch;
            return  extraBytesToRead;
        }
    }
}
