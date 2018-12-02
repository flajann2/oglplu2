/**
 *  @file eagine/shapes/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_DRAWING_1509260923_HPP
#define EAGINE_SHAPES_DRAWING_1509260923_HPP

#include "../types.hpp"

namespace eagine {
namespace shapes {

enum class primitive_type {
    points,
    lines,
    line_strip,
    line_loop,
    triangles,
    triangle_strip,
    triangle_fan
};

enum class index_data_type {
    none,
    unsigned_byte,
    unsigned_short,
    unsigned_int
};

struct draw_operation {
    primitive_type mode;
    index_data_type idx_type;
    span_size_t first;
    span_size_t count;
    unsigned phase;
    unsigned primitive_restart_index;
    bool primitive_restart : 1;
    bool cw_face_winding : 1;

    constexpr draw_operation() noexcept
      : mode(primitive_type::points)
      , idx_type(index_data_type::none)
      , first(0)
      , count(0)
      , phase(0)
      , primitive_restart_index(0)
      , primitive_restart(false)
      , cw_face_winding(false) {
    }
};

} // namespace shapes
} // namespace eagine

#endif // include guard
