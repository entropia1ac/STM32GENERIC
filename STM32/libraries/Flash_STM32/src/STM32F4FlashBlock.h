/*
  Copyright (c) 2017 Daniel Fekete

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifndef STM32F4F7FLASHBLOCK_H
#define STM32F4F7FLASHBLOCK_H
#include "FlashBlock.h"

#ifdef __cplusplus

class STM32F4EmbeddedFlashBlock: public FlashBlock {
public:
    STM32F4EmbeddedFlashBlock(uint32_t baseAddress, uint32_t size): FlashBlock(size), baseAddress(baseAddress) {
        HAL_FLASH_Unlock();
    };

    bool erase(uint32_t offset, uint32_t size);

    bool write(uint32_t offset, uint32_t size, uint8_t *data);

    bool read(uint32_t offset, uint32_t size, uint8_t *data);

    uint32_t baseAddress;

    uint32_t sectorError;
};

#endif /*__cplusplus*/
#endif /*STM32F4F7FLASHBLOCK_H*/
