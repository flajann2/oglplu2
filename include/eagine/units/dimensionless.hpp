/**
 *  @file eagine/unit/dimensionless.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_DIMENSIONLESS_HPP
#define EAGINE_UNITS_DIMENSIONLESS_HPP

#include "detail.hpp"
#include "fwd.hpp"

namespace eagine {
namespace units {

using dimensionless = bits::dimless;

template <>
struct dim_name<dimensionless> {
    static constexpr const char mp_str[] = "dimensionless";
};

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_DIMENSIONLESS_HPP
