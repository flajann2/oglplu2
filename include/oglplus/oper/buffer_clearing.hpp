/**
 *  @file oglplus/oper/buffer_clearing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_BUFFER_CLEARING_1509260923_HPP
#define OGLPLUS_OPER_BUFFER_CLEARING_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/span.hpp"
#include "../utils/vec_mat_traits.hpp"

namespace oglplus {
namespace oper {

struct rgba_value {
    GLfloat _v[4];

    rgba_value() = default;

    rgba_value(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
        _v[0] = r;
        _v[1] = g;
        _v[2] = b;
        _v[3] = a;
    }

    GLfloat red() const noexcept {
        return _v[0];
    }

    GLfloat green() const noexcept {
        return _v[1];
    }

    GLfloat blue() const noexcept {
        return _v[2];
    }

    GLfloat alpha() const noexcept {
        return _v[3];
    }
};

struct buffer_clearing_state {
    static outcome<void>
    clear_color(GLfloat r, GLfloat g, GLfloat b, GLfloat a) noexcept;

    static outcome<void> clear_color(const rgba_value& cc) noexcept {
        return clear_color(cc.red(), cc.green(), cc.blue(), cc.alpha());
    }

    template <
      typename V,
      typename = std::enable_if_t<has_canonical_type<V, GLfloat[4]>::value>>
    static outcome<void> clear_color(const V& cc) noexcept {
        auto ccv = element_view(cc);
        return clear_color(ccv[0], ccv[1], ccv[2], ccv[3]);
    }

    static outcome<void> clear_depth(GLfloat d) noexcept;

    static outcome<void> clear_stencil(GLint s) noexcept;

    static outcome<rgba_value> get_color_clear_value() noexcept;

    static outcome<GLfloat> get_depth_clear_value() noexcept;

    static outcome<GLint> get_stencil_clear_value() noexcept;
};

struct buffer_clearing_ops {
    static outcome<void> clear(enum_bitfield<buffer_select_bits> bits) noexcept;
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/buffer_clearing.inl>

#endif // include guard
