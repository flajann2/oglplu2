/**
 *  @file oglplus/sampler.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SAMPLER_1509260923_HPP
#define OGLPLUS_SAMPLER_1509260923_HPP

#include "enum/indexed_types.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "object/owner.hpp"
#include "sampler_name.hpp"
#include "utils/boolean.hpp"
#include "utils/gl_func.hpp"

namespace oglplus {
namespace oper {

struct sampler_ops {
    static outcome<void> bind_sampler(
      texture_unit unit, sampler_name sam) noexcept;

#if defined(GL_VERSION_4_4)
    template <typename S>
    static outcome<void> bind_samplers(
      texture_unit first,
      const object_names<tag::sampler, S>& samplers) noexcept;
#endif

    static outcome<sampler_name> sampler_binding(texture_unit unit) noexcept;

    static outcome<void> sampler_parameter_i(
      sampler_name sam, sampler_parameter param, GLint value) noexcept;

    static outcome<void> get_sampler_parameter_iv(
      sampler_name sam, sampler_parameter param, span<GLint> values) noexcept;

    static outcome<void> sampler_parameter_f(
      sampler_name sam, sampler_parameter param, GLfloat value) noexcept;

    static outcome<void> get_sampler_parameter_fv(
      sampler_name sam, sampler_parameter param, span<GLfloat> values) noexcept;

    template <typename R, typename T>
    static outcome<R> return_sampler_parameter_i(
      sampler_name sam, sampler_parameter parameter) noexcept;

    template <typename R>
    static outcome<R> return_sampler_parameter_f(
      sampler_name sam, sampler_parameter parameter) noexcept;

    static outcome<void> sampler_min_filter(
      sampler_name sam, texture_min_filter value) noexcept;

    static outcome<texture_min_filter> get_sampler_min_filter(
      sampler_name sam) noexcept;

    static outcome<void> sampler_mag_filter(
      sampler_name sam, texture_mag_filter value) noexcept;

    static outcome<texture_mag_filter> get_sampler_mag_filter(
      sampler_name sam) noexcept;

    static outcome<void> sampler_compare_mode(
      sampler_name sam, texture_compare_mode value) noexcept;

    static outcome<texture_compare_mode> get_sampler_compare_mode(
      sampler_name sam) noexcept;

    static outcome<void> sampler_compare_func(
      sampler_name sam, compare_function value) noexcept;

    static outcome<compare_function> get_sampler_compare_func(
      sampler_name sam) noexcept;

    static outcome<void> sampler_wrap(
      sampler_name sam,
      texture_wrap_coord coord,
      texture_wrap_mode value) noexcept;

    static outcome<texture_wrap_mode> get_sampler_wrap(
      sampler_name sam, texture_wrap_coord coord) noexcept;

    static outcome<void> sampler_wrap_s(
      sampler_name sam, texture_wrap_mode value) noexcept;

    static outcome<texture_wrap_mode> get_sampler_wrap_s(
      sampler_name sam) noexcept;

    static outcome<void> sampler_wrap_t(
      sampler_name sam, texture_wrap_mode value) noexcept;

    static outcome<texture_wrap_mode> get_sampler_wrap_t(
      sampler_name sam) noexcept;

    static outcome<void> sampler_wrap_r(
      sampler_name sam, texture_wrap_mode value) noexcept;

    static outcome<texture_wrap_mode> get_sampler_wrap_r(
      sampler_name sam) noexcept;

#if defined(GL_TEXTURE_LOD_BIAS)
    static outcome<void> sampler_lod_bias(
      sampler_name sam, GLfloat value) noexcept;

    static outcome<GLfloat> get_sampler_lod_bias(sampler_name sam) noexcept;
#endif

    static outcome<void> sampler_min_lod(
      sampler_name sam, GLfloat value) noexcept;

    static outcome<GLfloat> get_sampler_min_lod(sampler_name sam) noexcept;

    static outcome<void> sampler_max_lod(
      sampler_name sam, GLfloat value) noexcept;

    static outcome<GLfloat> get_sampler_max_lod(sampler_name sam) noexcept;
};

} // namespace oper

template <>
struct obj_dsa_ops<tag::sampler> : obj_zero_dsa_ops<tag::sampler> {
    typedef oper::sampler_ops _ops;

    using obj_zero_dsa_ops<tag::sampler>::obj_zero_dsa_ops;

    outcome<obj_dsa_ops&> min_filter(texture_min_filter value) noexcept {
        return {_ops::sampler_min_filter(*this, value), *this};
    }

    outcome<texture_min_filter> get_min_filter() const noexcept {
        return _ops::get_sampler_min_filter(*this);
    }

    outcome<obj_dsa_ops&> mag_filter(texture_mag_filter value) noexcept {
        return {_ops::sampler_mag_filter(*this, value), *this};
    }

    outcome<texture_mag_filter> get_mag_filter() const noexcept {
        return _ops::get_sampler_mag_filter(*this);
    }

    outcome<obj_dsa_ops&> compare_mode(texture_compare_mode value) noexcept {
        return {_ops::sampler_compare_mode(*this, value), *this};
    }

    outcome<texture_compare_mode> get_compare_mode() const noexcept {
        return _ops::get_sampler_compare_mode(*this);
    }

    outcome<obj_dsa_ops&> compare_func(compare_function value) noexcept {
        return {_ops::sampler_compare_func(*this, value), *this};
    }

    outcome<compare_function> get_compare_func() const noexcept {
        return _ops::get_sampler_compare_func(*this);
    }

    outcome<obj_dsa_ops&> wrap(
      texture_wrap_coord coord, texture_wrap_mode value) noexcept {
        return {_ops::sampler_wrap(*this, coord, value), *this};
    }

    outcome<texture_wrap_mode> get_wrap(texture_wrap_coord coord) const
      noexcept {
        return _ops::get_sampler_wrap(*this, coord);
    }

    outcome<obj_dsa_ops&> wrap_s(texture_wrap_mode value) noexcept {
        return {_ops::sampler_wrap_s(*this, value), *this};
    }

    outcome<texture_wrap_mode> get_wrap_s() const noexcept {
        return _ops::get_sampler_wrap_s(*this);
    }

    outcome<obj_dsa_ops&> wrap_t(texture_wrap_mode value) noexcept {
        return {_ops::sampler_wrap_t(*this, value), *this};
    }

    outcome<texture_wrap_mode> get_wrap_t() const noexcept {
        return _ops::get_sampler_wrap_t(*this);
    }

    outcome<obj_dsa_ops&> wrap_r(texture_wrap_mode value) noexcept {
        return {_ops::sampler_wrap_r(*this, value), *this};
    }

    outcome<texture_wrap_mode> get_wrap_r() const noexcept {
        return _ops::get_sampler_wrap_r(*this);
    }

#if defined(GL_TEXTURE_LOD_BIAS)
    outcome<obj_dsa_ops&> lod_bias(GLfloat value) noexcept {
        return {_ops::sampler_lod_bias(*this, value), *this};
    }

    outcome<GLfloat> get_lod_bias() const noexcept {
        return _ops::get_sampler_lod_bias(*this);
    }
#endif

    outcome<obj_dsa_ops&> min_lod(GLfloat value) noexcept {
        return {_ops::sampler_min_lod(*this, value), *this};
    }

    outcome<GLfloat> get_min_lod() const noexcept {
        return _ops::get_sampler_min_lod(*this);
    }

    outcome<obj_dsa_ops&> max_lod(GLfloat value) noexcept {
        return {_ops::sampler_max_lod(*this, value), *this};
    }

    outcome<GLfloat> get_max_lod() const noexcept {
        return _ops::get_sampler_max_lod(*this);
    }
};

template <>
struct obj_gen_del_ops<tag::sampler> {
    static deferred_error_handler _gen(span<GLuint> names) noexcept;

#if defined(GL_VERSION_4_5)
    static deferred_error_handler _create(span<GLuint> names) noexcept;
#endif

    static deferred_error_handler _delete(span<GLuint> names) noexcept;

    static outcome<boolean> _is_a(GLuint name) noexcept;
};

using sampler = object_owner<tag::sampler>;
template <std::size_t N>
using sampler_array = object_array_owner<tag::sampler, N>;

static const object_zero_and_ops<tag::sampler> no_sampler = {};

} // namespace oglplus

#include <oglplus/sampler.inl>

#endif // include guard
