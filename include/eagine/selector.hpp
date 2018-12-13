/**
 *  @file eagine/selector.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SELECTOR_1509260923_HPP
#define EAGINE_SELECTOR_1509260923_HPP

#include <cstdint>

namespace eagine {

template <std::uint64_t I>
struct selector {
    using type = selector;
};

} // namespace eagine

#endif // include guard
