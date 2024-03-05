#pragma once

#include <iostream>

void* operator new(size_t size) {
    auto ret = malloc(size);
    std::cout << "Allocated " << size << " bytes: " << std::hex << ret << std::dec << std::endl;
    return ret;
}

void operator delete(void* memory, size_t size) {
    std::cout << "Freeing " << size << " bytes: " << std::hex << memory << std::dec << std::endl;
    free(memory);
}

