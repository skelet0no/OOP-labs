#ifndef MEMORYRESOURCE_H
#define MEMORYRESOURCE_H

#include <memory_resource>
#include <list>

class CustomMemoryResource : public std::pmr::memory_resource {
public:
    CustomMemoryResource();
    ~CustomMemoryResource();

protected:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

private:
    std::list<void*> allocated_blocks;
    void* block;
    std::size_t block_size;
    std::size_t offset;
};

#endif //MEMORYRESOURCE_H
