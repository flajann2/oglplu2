/**
 *  @file oglplus/enum/names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_NAMES_HPP
#define OGLPLUS_ENUM_NAMES_HPP

#include "../error/outcome.hpp"
#include "indexed_value_names.hpp"
#include "value_names.hpp"

namespace oglplus {

template <typename EnumValue>
static inline auto enum_value_name(outcome<EnumValue> ocev) noexcept {
    return enum_value_name(ocev.value());
}

} // namespace oglplus

#endif // OGLPLUS_ENUM_NAMES_HPP
