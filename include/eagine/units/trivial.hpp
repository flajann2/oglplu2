/**
 *  @file eagine/unit/trivial.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_TRIVIAL_HPP
#define EAGINE_UNITS_TRIVIAL_HPP

#include "default.hpp"

namespace eagine {
namespace units {
namespace scales {

struct pi;

template <int I>
struct constant;

template <typename S1, typename S2>
struct divided;

} // namespace scales

namespace base {

// dimensions
struct time;
struct angle;

// units
struct radian;

} // namespace base

// dimensions
using time = dimension<base::time, 1>;
using angle = dimension<base::angle, 1>;

// units
using second = unit<time, si>;

using radian = unit<angle, si>;
using degree = scaled_dim_unit<
  angle,
  bits::unit_scales<
    bits::
      uni_sca<base::radian, scales::divided<scales::pi, scales::constant<180>>>,
    nothing_t>,
  si>;

} // namespace units
} // namespace eagine

#endif // EAGINE_UNITS_TRIVIAL_HPP
