/**
 *  @file eagine/math/coordinates.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_COORDINATES_HPP
#define EAGINE_MATH_COORDINATES_HPP

#include "../quantities.hpp"
#include "../valid_if/nonnegative.hpp"
#include "../valid_if/positive.hpp"
#include "functions.hpp"
#include "vector.hpp"
#include <tuple>

namespace eagine {
namespace math {
//------------------------------------------------------------------------------
template <typename T, bool V>
class unit_spherical_coordinates {
public:
    constexpr unit_spherical_coordinates() noexcept = default;

    constexpr unit_spherical_coordinates(
      radians_t<T> azimuth, radians_t<T> elevation) noexcept
      : _azim{azimuth}
      , _elev{elevation} {
    }

    radians_t<T> azimuth() const noexcept {
        return _azim;
    }

    radians_t<T> elevation() const noexcept {
        return _elev;
    }

private:
    radians_t<T> _azim{T(0)};
    radians_t<T> _elev{T(0)};
};
//------------------------------------------------------------------------------
template <typename T, bool V>
vector<T, 3, V> to_cartesian(unit_spherical_coordinates<T, V> c) noexcept {
    using std::abs;
    return vector<T, 3, V>::make(
      cos(c.azimuth()) * abs(cos(c.elevation())),
      sin(c.elevation()),
      -sin(c.azimuth()) * abs(cos(c.elevation())));
}
//------------------------------------------------------------------------------
template <typename T, bool V>
unit_spherical_coordinates<T, V> to_unit_spherical(vector<T, 3, V> v) noexcept {
    using R = unit_spherical_coordinates<T, V>;
    using std::abs;
    return abs(v.y()) > T(0) ? R(-arctan(v.z(), v.x()), arcsin(v.y()))
                             : R(radians_t<T>(0), arcsin(v.y()));
}
//------------------------------------------------------------------------------
} // namespace math
} // namespace eagine

#endif // EAGINE_MATH_COORDINATES_HPP
