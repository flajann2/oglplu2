/**
 *  @file oglplus/shapes/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_DRAWING_1509260923_HPP
#define OGLPLUS_SHAPES_DRAWING_1509260923_HPP

#include "../config/basic.hpp"
#include "../enum/types.hpp"
#include "../error/outcome.hpp"
#include "../utils/span.hpp"
#include <eagine/shapes/drawing.hpp>

namespace oglplus {
namespace shapes {

class draw_operation {
private:
    static primitive_type _translate(eagine::shapes::primitive_type) noexcept;

    static data_type _translate(eagine::shapes::index_data_type) noexcept;

    static span_size_t _byte_mult(eagine::shapes::index_data_type) noexcept;

    primitive_type _mode;
    data_type _idx_type;
    GLint _first;
    GLsizei _count;
    [[maybe_unused]] GLuint _phase;
    [[maybe_unused]] GLuint _primitive_restart_index;
    [[maybe_unused]] bool _primitive_restart : 1;
    bool _cw_face_winding : 1;

    const void* _idx_ptr() const noexcept;

public:
    constexpr draw_operation() noexcept
      : _mode(primitive_type(GL_NONE))
      , _idx_type(data_type(GL_NONE))
      , _first(0)
      , _count(0)
      , _phase(0)
      , _primitive_restart_index(0)
      , _primitive_restart(false)
      , _cw_face_winding(false) {
    }

    draw_operation(const eagine::shapes::draw_operation& draw_op) noexcept;

    bool indexed() const noexcept;

    outcome<void> draw() const noexcept;
};

outcome<void> draw_using_instructions(span<const draw_operation> ops) noexcept;

} // namespace shapes
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shapes/drawing.inl>
#endif

#endif // include guard
