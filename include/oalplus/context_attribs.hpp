/**
 *  @file oalplus/context_attribs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_CONTEXT_ATTRIBS_HPP
#define OALPLUS_CONTEXT_ATTRIBS_HPP

#include "enum/values_alc.hpp"
#include <eagine/key_val_list.hpp>

namespace oalplus {

struct context_attrib_traits {
    using key_type = context_attrib;
    using conv_type = ALCenum;
    using value_type = ALCint;

    static constexpr inline ALCint terminator() noexcept {
        return 0;
    }
};

template <std::size_t N>
using context_attribs = eagine::key_value_list<context_attrib_traits, N>;

using context_attrib_value =
  eagine::key_value_list_element<context_attrib_traits>;

static constexpr inline context_attrib_value operator|(
  context_attrib key, ALint value) noexcept {
    return {key, value};
}

static constexpr inline context_attrib_value operator|(
  context_attrib key, bool value) noexcept {
    return {key, value ? ALC_TRUE : ALC_FALSE};
}

} // namespace oalplus

#endif // OALPLUS_CONTEXT_ATTRIBS_HPP
