/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl.hpp>
#include <oglplus/sampler.hpp>
// clang-format on

using namespace oglplus;

void oglplus_sampler_test_1() {
    oglplus_object_name_test<sampler_name>();
    oglplus_object_test<sampler>();
}

void oglplus_sampler_test_ops1() {
    oper::sampler_ops gl;
    sampler sam;
    sampler_array<4> sams;

    gl.bind_sampler(texture_unit(0), sam);
    gl.sampler_binding(texture_unit(0));
    gl.bind_sampler(texture_unit(1), sams[0]);
#if defined(GL_VERSION_4_4)
    gl.bind_samplers(texture_unit(0), sams);
#endif

    texture_wrap_coord wrap_s(GL_TEXTURE_WRAP_S);

    gl.sampler_min_filter(sam, texture_min_filter(GL_LINEAR));
    gl.get_sampler_min_filter(sam);
    gl.sampler_min_filter(sams[0], texture_min_filter(GL_LINEAR));
    gl.sampler_mag_filter(sam, texture_mag_filter(GL_LINEAR));
    gl.get_sampler_mag_filter(sam);
    gl.sampler_compare_mode(sam, texture_compare_mode(GL_NONE));
    gl.get_sampler_compare_mode(sam);
    gl.sampler_compare_func(sam, compare_function(GL_EQUAL));
    gl.get_sampler_compare_func(sam);
    gl.sampler_wrap(sam, wrap_s, texture_wrap_mode(GL_REPEAT));
    gl.get_sampler_wrap(sam, wrap_s);

#if defined(GL_TEXTURE_LOD_BIAS)
    gl.sampler_lod_bias(sam, 1.0f);
    gl.get_sampler_lod_bias(sam);
#endif
    gl.sampler_min_lod(sam, -1000.0f);
    gl.get_sampler_min_lod(sam);
    gl.sampler_max_lod(sam, 1000.0f);
    gl.get_sampler_max_lod(sam);

    sam.min_filter(texture_min_filter(GL_NEAREST));
    sam.get_min_filter();
    sam.mag_filter(texture_mag_filter(GL_NEAREST));
    sam.get_mag_filter();

    sam.compare_mode(texture_compare_mode(GL_NONE));
    sam.get_compare_mode();
    sam.compare_func(compare_function(GL_LESS));
    sam.get_compare_func();
    sam.wrap(wrap_s, texture_wrap_mode(GL_REPEAT));
    sam.get_wrap(wrap_s);

#if defined(GL_TEXTURE_LOD_BIAS)
    sam.lod_bias(1.0f);
    sam.get_lod_bias();
#endif
    sam.min_lod(-1000.0f);
    sam.get_min_lod();
    sam.max_lod(1000.0f);
    sam.get_max_lod();
}

// TODO
