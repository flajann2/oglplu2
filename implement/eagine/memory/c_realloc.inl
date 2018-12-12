/**
 *  @file eagine/c_realloc.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cstdlib>

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
template <typename Policy>
inline owned_block
c_byte_reallocator<Policy>::allocate(size_type n, size_type a) noexcept {
    assert(a > 0);

    if(n == 0) {
        return {};
    }

    address p = as_address(std::malloc(std_size(n)));

    // TODO fix if misaligned ?
    assert(is_aligned_to(p, a));

    return this->acquire_block(block(p, n));
}
//------------------------------------------------------------------------------
template <typename Policy>
void c_byte_reallocator<Policy>::deallocate(
  owned_block&& b, size_type) noexcept {
    if(!b.empty()) {
        std::free(b.data());
        this->release_block(std::move(b));
    }
}
//------------------------------------------------------------------------------
template <typename Policy>
owned_block c_byte_reallocator<Policy>::reallocate(
  owned_block&& b, size_type n, size_type a) noexcept {
    assert(a > 0);

    if(n == 0) {
        deallocate(std::move(b), a);
        return {};
    }

    address p = as_address(std::realloc(b.data(), std_size(n)));

    this->release_block(std::move(b));

    // TODO fix if misaligned ?
    assert(is_aligned_to(p, a));

    return this->acquire_block({p, n});
}
//------------------------------------------------------------------------------
} // namespace memory
} // namespace eagine
