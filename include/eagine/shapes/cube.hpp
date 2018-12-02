/**
 *  @file eagine/shapes/cube.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_CUBE_1509260923_HPP
#define EAGINE_SHAPES_CUBE_1509260923_HPP

#include <cassert>
#include <eagine/config/basic.hpp>
#include "gen_base.hpp"

namespace eagine {
namespace shapes {

class unit_cube_gen : public centered_unit_shape_generator_base {
private:
    typedef centered_unit_shape_generator_base _base;

    static vertex_attrib_bits _attr_mask() noexcept;

    static vertex_attrib_bits _shared_attrs() noexcept;

    bool _only_shared_attribs() const noexcept;

    static int _coord_c(span_size_t v, span_size_t c) noexcept;

    static int _normal_c(span_size_t f, span_size_t c) noexcept;

    static int _tangential_c(span_size_t f, span_size_t c) noexcept;

    static int _bitangential_c(span_size_t f, span_size_t c) noexcept;

    template <typename T>
    void _indices(const span<T>& dest) noexcept;

    static span_size_t _face_vert(
      span_size_t f, span_size_t t, span_size_t v) noexcept;

public:
    unit_cube_gen(vertex_attrib_bits attr_bits) noexcept;

    span_size_t vertex_count() override;

    void positions(const span<float>& dest) noexcept;

    void normals(const span<float>& dest) noexcept;

    void tangentials(const span<float>& dest) noexcept;

    void bitangentials(const span<float>& dest) noexcept;

    void face_coords(const span<float>& dest) noexcept;

    void attrib_values(
      vertex_attrib_kind attr, const span<float>& dest) override;

    index_data_type index_type() override;

    span_size_t index_count() override;

    void indices(const span<unsigned>& dest) override;

    span_size_t operation_count() override;

    void instructions(const span<draw_operation>& ops) override;
};

} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/cube.inl>
#endif

#endif // include guard
