/**
 *  @file eagine/math/matrix_perspective.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_PERSPECTIVE_HPP
#define EAGINE_MATH_MATRIX_PERSPECTIVE_HPP

#include "../quantities.hpp"
#include "matrix_ctr.hpp"

namespace eagine {
namespace math {

// perspective
template <typename X>
struct perspective;

// is_matrix_constructor<perspective>
template <typename T, int N, bool RM, bool V>
struct is_matrix_constructor<perspective<matrix<T, N, N, RM, V>>>
  : std::true_type {};

// perspective matrix 4x4
template <typename T, bool RM, bool V>
struct perspective<matrix<T, 4, 4, RM, V>> {
    using _dT = vect::data_t<T, 6, V>;
    _dT _v;

    constexpr perspective(const _dT& v) noexcept
      : _v(v) {
    }

    constexpr perspective(
      T x_left, T x_right, T y_bottom, T y_top, T z_near, T z_far) noexcept
      : _v{x_left, x_right, y_bottom, y_top, z_near, z_far} {
    }

    constexpr inline T _x_left() const noexcept {
        return _v[0];
    }

    constexpr inline T _x_right() const noexcept {
        return _v[1];
    }

    constexpr inline T _y_bottom() const noexcept {
        return _v[2];
    }

    constexpr inline T _y_top() const noexcept {
        return _v[3];
    }

    constexpr inline T _z_near() const noexcept {
        return _v[4];
    }

    constexpr inline T _z_far() const noexcept {
        return _v[5];
    }

    static inline perspective square(
      radians_t<T> fov, T z_near, T z_far) noexcept {
        assert(T(fov) > T(0));

        T x_right = z_near * tan(fov * T(0.5));
        T x_left = -x_right;

        T y_bottom = x_left;
        T y_top = x_right;

        return perspective(x_left, x_right, y_bottom, y_top, z_near, z_far);
    }

    static inline perspective x(
      radians_t<T> xfov, T aspect, T z_near, T z_far) noexcept {
        assert(aspect > T(0));
        assert(T(xfov) > T(0));

        T x_right = z_near * tan(xfov * T(0.5));
        T x_left = -x_right;

        T y_bottom = x_left / aspect;
        T y_top = x_right / aspect;

        return perspective(x_left, x_right, y_bottom, y_top, z_near, z_far);
    }

    static inline perspective y(
      radians_t<T> yfov, T aspect, T z_near, T z_far) noexcept {
        assert(aspect > T(0));
        assert(T(yfov) > T(0));

        T y_top = z_near * tan(yfov * T(0.5));
        T y_bottom = -y_top;

        T x_left = y_bottom * aspect;
        T x_right = y_top * aspect;

        return perspective(x_left, x_right, y_bottom, y_top, z_near, z_far);
    }

    constexpr inline T _m00() const noexcept {
        return (T(2) * _z_near()) / (_x_right() - _x_left());
    }

    constexpr inline T _m11() const noexcept {
        return (T(2) * _z_near()) / (_y_top() - _y_bottom());
    }

    constexpr inline T _m22() const noexcept {
        return -(_z_far() + _z_near()) / (_z_far() - _z_near());
    }

    constexpr inline T _m20() const noexcept {
        return (_x_right() + _x_left()) / (_x_right() - _x_left());
    }

    constexpr inline T _m21() const noexcept {
        return (_y_top() + _y_bottom()) / (_y_top() - _y_bottom());
    }

    constexpr inline T _m23() const noexcept {
        return -T(1);
    }

    constexpr inline T _m32() const noexcept {
        return -(T(2) * _z_far() * _z_near()) / (_z_far() - _z_near());
    }

    constexpr inline matrix<T, 4, 4, true, V> _make(std::true_type) const
      noexcept {
        return matrix<T, 4, 4, true, V>{{{_m00(), T(0), _m20(), T(0)},
                                         {T(0), _m11(), _m21(), T(0)},
                                         {T(0), T(0), _m22(), _m32()},
                                         {T(0), T(0), _m23(), T(0)}}};
    }

    constexpr inline matrix<T, 4, 4, false, V> _make(std::false_type) const
      noexcept {
        return matrix<T, 4, 4, false, V>{{{_m00(), T(0), T(0), T(0)},
                                          {T(0), _m11(), T(0), T(0)},
                                          {_m20(), _m21(), _m22(), _m23()},
                                          {T(0), T(0), _m32(), T(0)}}};
    }

    constexpr inline matrix<T, 4, 4, RM, V> operator()() const noexcept {
        return _make(bool_constant<RM>());
    }
};

// reorder_mat_ctr(perspective)
template <typename T, int N, bool RM, bool V>
static constexpr inline perspective<matrix<T, N, N, !RM, V>> reorder_mat_ctr(
  const perspective<matrix<T, N, N, RM, V>>& c) noexcept {
    return {c._v};
}

// matrix_*
template <typename T, bool V>
using matrix_perspective =
  convertible_matrix_constructor<perspective<matrix<T, 4, 4, true, V>>>;

} // namespace math
} // namespace eagine

#endif // EAGINE_MATH_MATRIX_PERSPECTIVE_HPP
