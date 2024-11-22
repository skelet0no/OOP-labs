#include "MemoryResource.h"
#include <cstdlib>
#include <iostream>

CustomMemoryResource::CustomMemoryResource()
    : block(nullptr), block_size(1024 * 1024), offset(0) {
    block = std::malloc(block_size);
    if (!block) {
        throw std::bad_alloc();
    }
}

CustomMemoryResource::~CustomMemoryResource() {
    std::free(block);
}

void* CustomMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    if (offset + bytes > block_size) {
        throw std::bad_alloc();
    }
    void* p = static_cast<char*>(block) + offset;
    offset += bytes;
    allocated_blocks.push_back(p);
    return p;
}

void CustomMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    allocated_blocks.remove(p);
}

bool CustomMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}
