/**
 *  @file oglplus/oper/object_common.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_OBJECT_COMMON_HPP
#define OGLPLUS_OPER_OBJECT_COMMON_HPP

#include "../enum/types.hpp"
#include "../error/outcome.hpp"
#include "../object/gl_name.hpp"
#include "../utils/gl_func.hpp"
#include "synchronization.hpp"

namespace oglplus {
namespace oper {

struct object_common_ops {
#if defined(GL_VERSION_4_3)
    static outcome<GLsizei> get_max_label_length() noexcept;

    template <GLenum ObjectType>
    static outcome<void> object_label(
      object_name<oglplus::tag::gl_obj_tag<ObjectType>> obj,
      string_view label) noexcept;

    static outcome<void> object_label(
      const sync_object& obj, string_view label) noexcept;

    template <GLenum ObjectType>
    static outcome<string_view> get_object_label(
      object_name<oglplus::tag::gl_obj_tag<ObjectType>> obj,
      string_span storage) noexcept;

    static outcome<string_view> get_object_label(
      const sync_object& obj, string_span label) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/object_common.inl>

#endif // OGLPLUS_OPER_OBJECT_COMMON_HPP
