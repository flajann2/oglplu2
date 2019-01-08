/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include <oglplus/gl.hpp>
#include <eagine/maybe_unused.hpp>
#include <oglplus/buffer_name.hpp>
#include <oglplus/framebuffer_name.hpp>
#include <oglplus/operations.hpp>
#include <oglplus/program_name.hpp>
#include <oglplus/program_pipeline_name.hpp>
#include <oglplus/query_name.hpp>
#include <oglplus/renderbuffer_name.hpp>
#include <oglplus/sampler_name.hpp>
#include <oglplus/shader_name.hpp>
#include <oglplus/texture_name.hpp>
#include <oglplus/transform_feedback_name.hpp>
#include <string>
// clang-format on

using namespace oglplus;

void oglplus_object_common_test() {
    using namespace oglplus;

    oper::object_common_ops gl;

    EAGINE_MAYBE_UNUSED(gl);

#if defined(GL_VERSION_4_3)
    std::string storage(
      eagine::std_size(gl.get_max_label_length().value()), ' ');
    string_span dest(storage);

    buffer_name buf;
    shader_name shd;
    program_name prg;
    program_pipeline_name ppl;
    query_name qry;
    transform_feedback_name xfb;
    texture_name tex;
    sampler_name sam;
    renderbuffer_name rbo;
    framebuffer_name fbo;
    sync_object syn;

    gl.object_label(buf, "test buffer");
    gl.object_label(shd, "test shader");
    gl.object_label(prg, "test program");
    gl.object_label(ppl, "test program pipeline");
    gl.object_label(xfb, "test transform feedback");
    gl.object_label(sam, "test sampler");
    gl.object_label(tex, "test texture");
    gl.object_label(rbo, "test renderbuffer");
    gl.object_label(fbo, "test framebuffer");
    gl.object_label(qry, "test query object");
    gl.object_label(syn, "test sync object");

    gl.get_object_label(buf, dest);
    gl.get_object_label(shd, dest);
    gl.get_object_label(prg, dest);
    gl.get_object_label(ppl, dest);
    gl.get_object_label(xfb, dest);
    gl.get_object_label(sam, dest);
    gl.get_object_label(tex, dest);
    gl.get_object_label(rbo, dest);
    gl.get_object_label(fbo, dest);
    gl.get_object_label(qry, dest);
    gl.get_object_label(syn, dest);
#endif
}

void oglplus_numeric_queries_test() {
    using namespace oglplus;

    oper::numeric_queries gl;

    gl.get_integer_v(binding_query(GL_DRAW_FRAMEBUFFER_BINDING), span<GLint>());

    gl.get_boolean_v(numeric_query(GL_DEPTH_TEST), span<GLboolean>());
    gl.get_boolean(numeric_query(GL_DEPTH_TEST));

    gl.get_integer_v(numeric_query(GL_ACTIVE_TEXTURE), span<GLint>());
    gl.get_integer(numeric_query(GL_ACTIVE_TEXTURE));

#if defined(GL_VERSION_3_2)
    gl.get_integer64_v(
      numeric_query(GL_SHADER_STORAGE_BUFFER_START), span<GLint64>());
    gl.get_integer64(numeric_query(GL_SHADER_STORAGE_BUFFER_START));
#endif

    gl.get_float_v(numeric_query(GL_MAX_TEXTURE_LOD_BIAS), span<GLfloat>());
    gl.get_float(numeric_query(GL_MAX_TEXTURE_LOD_BIAS));

#if defined(GLdouble)
    gl.get_double_v(numeric_query(GL_MAX_TEXTURE_LOD_BIAS), span<GLdouble>());
    gl.get_double(numeric_query(GL_MAX_TEXTURE_LOD_BIAS));
#endif

#if defined(GL_VERSION_3_2)
    gl.get_boolean_v(numeric_query(GL_DEPTH_TEST), 0, span<GLboolean>());
    gl.get_boolean(numeric_query(GL_DEPTH_TEST), 0);

    gl.get_integer_v(numeric_query(GL_ACTIVE_TEXTURE), 0, span<GLint>());
    gl.get_integer(numeric_query(GL_ACTIVE_TEXTURE), 0);

    gl.get_integer64_v(
      numeric_query(GL_SHADER_STORAGE_BUFFER_START), 0, span<GLint64>());
    gl.get_integer64(numeric_query(GL_SHADER_STORAGE_BUFFER_START), 0);
#endif

#if defined(GL_VERSION_4_1)
    gl.get_float_v(numeric_query(GL_MAX_TEXTURE_LOD_BIAS), 0, span<GLfloat>());
    gl.get_float(numeric_query(GL_MAX_TEXTURE_LOD_BIAS), 0);

    gl.get_double_v(
      numeric_query(GL_MAX_TEXTURE_LOD_BIAS), 0, span<GLdouble>());
    gl.get_double(numeric_query(GL_MAX_TEXTURE_LOD_BIAS), 0);
#endif
}

void oglplus_internal_format_queries_test() {
    using namespace oglplus;

    oper::internal_format_queries gl;
    GLint temp = 0;
    GLint64 temp64 = 0;

    EAGINE_MAYBE_UNUSED(gl);
    EAGINE_MAYBE_UNUSED(temp);
    EAGINE_MAYBE_UNUSED(temp64);

#if defined(GL_VERSION_4_2)
    gl.get_internal_format_iv(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED),
      internal_format_parameter(GL_INTERNALFORMAT_SUPPORTED),
      {&temp, 1});
#endif

#if defined(GL_VERSION_4_3)
    gl.get_internal_format_i64v(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED),
      internal_format_parameter(GL_INTERNALFORMAT_SUPPORTED),
      {&temp64, 1});

    gl.is_internal_format_supported(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.is_internal_format_preferred(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.is_internal_format_compressed(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.has_internal_format_color_components(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.has_internal_format_depth_components(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.has_internal_format_stencil_components(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.supports_internal_format_framebuffer_blend(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.supports_internal_format_mipmap(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.supports_internal_format_filter(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.get_internal_format_framebuffer_renderable_support(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.get_internal_format_framebuffer_renderable_layered_support(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.get_internal_format_read_pixels_support(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));

    gl.get_internal_format_auto_generate_mipmap_support(
      internal_format_target(GL_RENDERBUFFER),
      pixel_data_internal_format(GL_RED));
#endif
}

void oglplus_viewport_test() {
    using namespace oglplus;

    oper::viewport_state gl;

    gl.viewport(0, 0, 800, 600);
    gl.viewport(800, 600);
    gl.get_viewport();

#if defined(GL_VERSION_4_1)
    gl.viewport(0, 0, 0, 800, 600);
    gl.viewport(1, oper::viewport_extents());
    gl.viewport_array(2, span<const GLfloat>());
    gl.get_viewport(0);
#endif
}

void oglplus_synchronization_test() {
    using namespace oglplus;

    oper::synchronization gl;

#if defined(GL_VERSION_4_2) || defined(GL_ARB_shader_image_load_store)
    gl.memory_barrier(enum_bitfield<memory_barrier_bits>(0));
#endif

#if defined(GL_ES_VERSION_3_1)
    gl.memory_barrier_by_region(enum_bitfield<memory_barrier_bits>(0));
#endif

#if defined(GL_VERSION_4_5)
    gl.texture_barrier();
#endif

    gl.flush();
    gl.finish();

#if defined(GL_VERSION_3_2) || defined(GL_ARB_sync)
    sync_object so = gl.fence_sync();
    gl.is_sync(so);
    gl.wait_sync(so);
    gl.get_sync_status(so);
    gl.is_sync_signaled(so);
    gl.delete_sync(so);
#endif
}

void oglplus_debugging_test() {
    using namespace oglplus;

#if defined(GL_VERSION_4_3)
    oper::debugging gl;

    debug_output_source src(GL_DEBUG_SOURCE_APPLICATION);
    debug_output_type typ(GL_DEBUG_TYPE_ERROR);
    debug_output_severity svt(GL_DEBUG_SEVERITY_LOW);
    span<GLuint> ids;

    gl.push_debug_group(src, 123, "debug group");
    gl.pop_debug_group();

    gl.debug_message_control(src, typ, svt, ids, true);
    gl.debug_message_insert(src, typ, 123, svt, "debug message");

    gl.debug_message_callback(nullptr, nullptr);

    gl.get_debug_message_log(
      0,
      span<debug_output_source>(),
      span<debug_output_type>(),
      span<GLuint>(),
      span<debug_output_severity>(),
      span<GLsizei>(),
      span<char>());
#endif
}

void oglplus_buffer_clearing_state_test() {
    using namespace oglplus;

    oper::buffer_clearing_state gl;

    gl.clear_color(1.f, 1.f, 1.f, 0.f);
    gl.clear_color(oper::rgba_value(0.f, 0.f, 0.f, 0.f));
    gl.clear_depth(0.f);
    gl.clear_stencil(0);

    oper::rgba_value cc = gl.get_color_clear_value();
    GLfloat cd = gl.get_depth_clear_value();
    GLint cs = gl.get_stencil_clear_value();
    EAGINE_MAYBE_UNUSED(cc);
    EAGINE_MAYBE_UNUSED(cd);
    EAGINE_MAYBE_UNUSED(cs);
}

void oglplus_buffer_clearing_ops_test() {
    using namespace oglplus;

    oper::buffer_clearing_ops gl;

    gl.clear(enum_bitfield<buffer_select_bits>(0));
}

void oglplus_capability_state_test() {
    using namespace oglplus;

    oper::capability_state gl;

    gl.enable(capability(GL_DEPTH_TEST));
    gl.disable(capability(GL_DEPTH_TEST));
    gl.is_enabled(capability(GL_DEPTH_TEST));

#if defined(GL_VERSION_3_0)
    gl.enable(capability(GL_BLEND), 1);
    gl.disable(capability(GL_BLEND), 1);
    gl.is_enabled(capability(GL_BLEND), 1);
#endif

#if defined(GL_CLIP_DISTANCE0)
    gl.enable(clip_plane(0));
    gl.disable(clip_plane(0));
    gl.is_enabled(clip_plane(0));
#endif

#if defined(GL_ARB_compatibility)
    gl.enable_client_state(client_capability(GL_COLOR_ARRAY));
    gl.disable_client_state(client_capability(GL_COLOR_ARRAY));
    gl.is_enabled(client_capability(GL_COLOR_ARRAY));

    gl.get_red_bits();
    gl.get_green_bits();
    gl.get_blue_bits();
    gl.get_alpha_bits();
    gl.get_depth_bits();
    gl.get_stencil_bits();
    gl.has_doublebuffer();
    gl.is_stereo();
#endif

#if defined(GL_VERSION_4_5)
    gl.get_graphics_reset_status();
#endif
}

void oglplus_blending_state_test() {
    using namespace oglplus;

    oper::blending_state gl;

    EAGINE_MAYBE_UNUSED(gl);

    gl.blend_equation(blend_equation(GL_MIN));
    gl.blend_equation_separate(blend_equation(GL_MIN), blend_equation(GL_MAX));

    gl.blend_func(blend_function(GL_ONE), blend_function(GL_ZERO));

    gl.blend_func_separate(
      blend_function(GL_ONE),
      blend_function(GL_ONE),
      blend_function(GL_ZERO),
      blend_function(GL_ZERO));

#if defined(GL_VERSION_4_0)
    gl.blend_equation(1, blend_equation(GL_MIN));
    gl.blend_equation_separate(
      1, blend_equation(GL_MIN), blend_equation(GL_MAX));
    gl.blend_func(1, blend_function(GL_ONE), blend_function(GL_ZERO));
    gl.blend_func_separate(
      1,
      blend_function(GL_ONE),
      blend_function(GL_ONE),
      blend_function(GL_ZERO),
      blend_function(GL_ZERO));
#endif
}

void oglplus_computing_ops_test() {
    using namespace oglplus;

    oper::computing_ops gl;

    EAGINE_MAYBE_UNUSED(gl);

#if defined(GL_VERSION_4_2)
    gl.dispatch_compute(8, 16, 32);
#endif

#if defined(GL_VERSION_4_3)
    gl.dispatch_compute_indirect(0);
#endif
}

void oglplus_drawing_state_test() {
    using namespace oglplus;

    oper::drawing_state gl;

    EAGINE_MAYBE_UNUSED(gl);

#if defined(GL_VERSION_3_1)
    gl.primitive_restart_index(0);
#endif

#if defined(GL_VERSION_4_0)
    gl.patch_parameter_i(patch_parameter(GL_PATCH_DEFAULT_INNER_LEVEL), 4);
    gl.patch_parameter(patch_parameter(GL_PATCH_VERTICES), span<GLfloat>());
#endif
}

void oglplus_drawing_ops_test() {
    using namespace oglplus;

    oper::drawing_ops gl;
    transform_feedback_name xfb;

    EAGINE_MAYBE_UNUSED(gl);
    EAGINE_MAYBE_UNUSED(xfb);

    gl.draw_arrays(primitive_type(GL_TRIANGLES), 0, 3);

#if defined(GL_VERSION_3_0)
    gl.multi_draw_arrays(
      primitive_type(GL_TRIANGLES), span<GLint>(), span<GLsizei>());
#endif

    gl.draw_elements(
      primitive_type(GL_TRIANGLES), 12, index_type(GL_UNSIGNED_BYTE));

#if defined(GL_VERSION_3_0)
    gl.multi_draw_elements(
      primitive_type(GL_TRIANGLES),
      span<GLsizei>(),
      index_type(GL_UNSIGNED_BYTE),
      span<const GLvoid*>());
#endif

#if defined(GL_VERSION_3_1)
    gl.draw_arrays_instanced(primitive_type(GL_TRIANGLES), 0, 3, 10);

    gl.draw_elements_instanced(
      primitive_type(GL_TRIANGLES), 12, index_type(GL_UNSIGNED_BYTE), 10);
#endif

#if defined(GL_VERSION_3_2)
    gl.draw_elements_base_vertex(
      primitive_type(GL_TRIANGLES), 12, index_type(GL_UNSIGNED_BYTE), 10);

    gl.multi_draw_elements_base_vertex(
      primitive_type(GL_TRIANGLES),
      span<GLsizei>(),
      index_type(GL_UNSIGNED_BYTE),
      span<const GLvoid*>(),
      span<GLint>());

    gl.draw_elements_instanced_base_vertex(
      primitive_type(GL_TRIANGLES), 12, index_type(GL_UNSIGNED_BYTE), 4, 10);
#endif

#if defined(GL_VERSION_4_2)
    gl.draw_arrays_instanced_base_instance(
      primitive_type(GL_TRIANGLES), 0, 3, 10, 123);

    gl.draw_elements_instanced_base_instance(
      primitive_type(GL_TRIANGLES), 12, index_type(GL_UNSIGNED_BYTE), 10, 123);

    gl.draw_elements_instanced_base_vertex_base_instance(
      primitive_type(GL_TRIANGLES),
      12,
      index_type(GL_UNSIGNED_BYTE),
      10,
      12,
      345);
#endif

#if defined(GL_VERSION_4_0)
    gl.draw_arrays_indirect(primitive_type(GL_TRIANGLES), nullptr);

    gl.draw_elements_indirect(
      primitive_type(GL_TRIANGLES), index_type(GL_UNSIGNED_BYTE), nullptr);
#endif

#if defined(GL_VERSION_4_0)
    gl.draw_transform_feedback(primitive_type(GL_TRIANGLES), xfb);

    gl.draw_transform_feedback_stream(primitive_type(GL_TRIANGLES), xfb, 2);
#endif

#if defined(GL_VERSION_4_2)
    gl.draw_transform_feedback_instanced(primitive_type(GL_TRIANGLES), xfb, 10);

    gl.draw_transform_feedback_stream_instanced(
      primitive_type(GL_TRIANGLES), xfb, 2, 10);
#endif
}

void oglplus_compatibility_drawing_test() {
    using namespace oglplus;

#if defined(GL_ARB_compatibility)
    oper::compatibility_drawing gl;
    using eagine::memory::view;

    gl.begin(old_primitive_type(GL_QUADS));
    gl.end();

    // vertex
    gl.vertex_s(0, 1);
    gl.vertex_s(0, 1, 2);
    gl.vertex_s(0, 1, 2, 1);
    gl.vertex(view(std::array<GLshort, 4>{{0, 1, 2, 1}}));

    gl.vertex_i(0, 1);
    gl.vertex_i(0, 1, 2);
    gl.vertex_i(0, 1, 2, 1);
    gl.vertex(view(std::array<GLint, 4>{{0, 1, 2, 1}}));

    gl.vertex_f(0.f, 1.f);
    gl.vertex_f(0.f, 1.f, 2.f);
    gl.vertex_f(0.f, 1.f, 2.f, 1.f);
    gl.vertex(view(std::array<GLfloat, 4>{{0.f, 1.f, 2.f, 1.f}}));

    gl.vertex_d(0.0, 1.0);
    gl.vertex_d(0.0, 1.0, 2.0);
    gl.vertex_d(0.0, 1.0, 2.0, 1.0);
    gl.vertex(view(std::array<GLdouble, 4>{{0.0, 1.0, 2.0, 1.0}}));

    // color
    gl.color_ub(0x00, 0x00, 0x00);
    gl.color_ub(0x00, 0x00, 0x00, 0x00);
    gl.color(view(std::array<GLubyte, 4>{{0x00, 0x00, 0x00, 0x00}}));

    gl.color_i(0, 0, 0);
    gl.color_i(0, 0, 0, 1);
    gl.color(view(std::array<GLint, 4>{{0, 0, 0, 1}}));

    gl.color_f(0.f, 0.f, 0.f);
    gl.color_f(0.f, 0.f, 0.f, 0.f);
    gl.color(view(std::array<GLfloat, 4>{{0.f, 0.f, 0.f, 0.f}}));

    gl.color_d(0.0, 0.0, 0.0);
    gl.color_d(0.0, 0.0, 0.0, 0.0);
    gl.color(view(std::array<GLdouble, 4>{{0.0, 0.0, 0.0, 0.0}}));

    // tex_coord
    gl.tex_coord_s(0, 1);
    gl.tex_coord_s(0, 1, 2);
    gl.tex_coord_s(0, 1, 2, 1);
    gl.tex_coord(view(std::array<GLshort, 4>{{0, 1, 2, 1}}));

    gl.tex_coord_i(0, 1);
    gl.tex_coord_i(0, 1, 2);
    gl.tex_coord_i(0, 1, 2, 1);
    gl.tex_coord(view(std::array<GLint, 4>{{0, 1, 2, 1}}));

    gl.tex_coord_f(0.f, 1.f);
    gl.tex_coord_f(0.f, 1.f, 2.f);
    gl.tex_coord_f(0.f, 1.f, 2.f, 1.f);
    gl.tex_coord(view(std::array<GLfloat, 4>{{0.f, 1.f, 2.f, 1.f}}));

    gl.tex_coord_d(0.0, 1.0);
    gl.tex_coord_d(0.0, 1.0, 2.0);
    gl.tex_coord_d(0.0, 1.0, 2.0, 1.0);
    gl.tex_coord(view(std::array<GLdouble, 4>{{0.0, 1.0, 2.0, 1.0}}));

#endif
}

void oglplus_compatibility_matrix_test() {
    using namespace oglplus;

#if defined(GL_ARB_compatibility)
    oper::compatibility_matrix gl;

    std::array<GLfloat, 16> matfa{{1.f,
                                   0.f,
                                   0.f,
                                   0.f,
                                   0.f,
                                   1.f,
                                   0.f,
                                   0.f,
                                   0.f,
                                   0.f,
                                   1.f,
                                   0.f,
                                   0.f,
                                   0.f,
                                   0.f,
                                   1.f}};
    span<GLfloat> matf = cover(matfa);

    std::array<GLdouble, 16> matda{{1.0,
                                    0.0,
                                    0.0,
                                    0.0,
                                    0.0,
                                    1.0,
                                    0.0,
                                    0.0,
                                    0.0,
                                    0.0,
                                    1.0,
                                    0.0,
                                    0.0,
                                    0.0,
                                    0.0,
                                    1.0}};
    span<GLdouble> matd = cover(matda);

    gl.matrix_mode(old_matrix_mode(GL_PROJECTION));

    gl.push_matrix();
#ifdef GL_EXT_direct_state_access
    gl.push_matrix(old_matrix_mode(GL_PROJECTION));
#endif

    gl.pop_matrix();
#ifdef GL_EXT_direct_state_access
    gl.pop_matrix(old_matrix_mode(GL_PROJECTION));
#endif

    gl.load_identity();
#ifdef GL_EXT_direct_state_access
    gl.load_identity(old_matrix_mode(GL_PROJECTION));
#endif

    gl.load_matrix(matf);
#ifdef GL_EXT_direct_state_access
    gl.load_matrix(old_matrix_mode(GL_PROJECTION), matf);
#endif

    gl.load_transpose_matrix(matf);
#ifdef GL_EXT_direct_state_access
    gl.load_transpose_matrix(old_matrix_mode(GL_PROJECTION), matf);
#endif

    gl.load_matrix(matd);
#ifdef GL_EXT_direct_state_access
    gl.load_matrix(old_matrix_mode(GL_PROJECTION), matd);
#endif

    gl.load_transpose_matrix(matd);
#ifdef GL_EXT_direct_state_access
    gl.load_transpose_matrix(old_matrix_mode(GL_PROJECTION), matd);
#endif

    gl.translate_f(1.f, 0.f, 0.f);
#ifdef GL_EXT_direct_state_access
    gl.translate_f(old_matrix_mode(GL_PROJECTION), 1.f, 0.f, 0.f);
#endif

    gl.translate_d(1.0, 0.0, 0.0);
#ifdef GL_EXT_direct_state_access
    gl.translate_d(old_matrix_mode(GL_PROJECTION), 1.0, 0.0, 0.0);
#endif

    gl.rotate_f(degrees_t<GLfloat>(0.f), 1.f, 0.f, 0.f);
#ifdef GL_EXT_direct_state_access
    gl.rotate_f(
      old_matrix_mode(GL_PROJECTION), degrees_t<GLfloat>(0.f), 1.f, 0.f, 0.f);
#endif

    gl.rotate_d(degrees_t<GLfloat>(0.0), 1.0, 0.0, 0.0);
#ifdef GL_EXT_direct_state_access
    gl.rotate_d(
      old_matrix_mode(GL_PROJECTION), degrees_t<GLfloat>(0.0), 1.0, 0.0, 0.0);
#endif

    gl.scale_f(1.f, 2.f, 1.f);
#ifdef GL_EXT_direct_state_access
    gl.scale_f(old_matrix_mode(GL_MODELVIEW), 1.f, 2.f, 1.f);
#endif

    gl.scale_d(1.0, 2.0, 1.0);
#ifdef GL_EXT_direct_state_access
    gl.scale_d(old_matrix_mode(GL_MODELVIEW), 1.0, 2.0, 1.0);
#endif

    gl.ortho_f(1.f, 1.f, 1.f, 1.f, 1.f, 1.f);
    gl.ortho(1.0, 1.0, 1.0, 1.0, 1.0, 1.0);

#ifdef GL_EXT_direct_state_access
    gl.ortho(old_matrix_mode(GL_MODELVIEW), 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
#endif

    gl.frustum(1.0, 1.0, 1.0, 1.0, 1.0, 1.0);

#ifdef GL_EXT_direct_state_access
    gl.frustum(old_matrix_mode(GL_MODELVIEW), 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
#endif

#endif
}

void oglplus_scissor_state_test() {
    using namespace oglplus;

    oper::scissor_state gl;

    gl.scissor(16, 16, 32, 32);

#if defined(GL_VERSION_4_1)
    gl.scissor(2, 16, 16, 32, 32);
#endif
}

void oglplus_rasterization_state_test() {
    using namespace oglplus;

    oper::rasterization_state gl;

    gl.front_face(face_orientation(GL_CCW));
    gl.get_front_face();
    gl.cull_face(face(GL_BACK));
    gl.get_cull_face_mode();

#if defined(GL_VERSION_4_5)
    gl.clip_control(
      clip_origin(GL_LOWER_LEFT), clip_depth_mode(GL_NEGATIVE_ONE_TO_ONE));
#endif

    gl.depth_func(compare_function(GL_LESS));
    gl.get_depth_func();

#if defined(GL_VERSION_4_1)
    gl.depth_range_f(0.0f, 1.0f);
#endif

#if defined(GL_DOUBLE)
    gl.depth_range(0.0, 1.0);
#if defined(GL_VERSION_4_1)
    gl.depth_range(1, 0.0, 1.0);
#endif
#endif

#if defined(GL_VERSION_3_0)
    gl.polygon_mode(face(GL_FRONT), polygon_mode(GL_FILL));
#endif

    gl.polygon_offset(0.0f, 0.0f);
    gl.get_polygon_offset_factor();
    gl.get_polygon_offset_units();

#if defined(GL_VERSION_4_6) || defined(GL_EXT_polygon_offset_clamp)
    gl.polygon_offset_clamp(0.0f, 0.0f, 0.0f);
    gl.get_polygon_offset_clamp();
#endif

    gl.line_width(2.0f);
    gl.get_line_width();

#if defined(GL_VERSION_3_0)
    gl.point_size(2.0f);
    gl.get_point_size();

    gl.point_parameter(point_parameter(GL_POINT_FADE_THRESHOLD_SIZE), 2.0f);
    gl.get_point_parameter(point_parameter(GL_POINT_FADE_THRESHOLD_SIZE));
#endif

#if defined(GL_VERSION_4_6) || defined(GL_EXT_polygon_offset_clamp)
    gl.provoking_vertex(provoke_mode(GL_FIRST_VERTEX_CONVENTION));
    gl.get_provoking_vertex();
#endif

#if defined(GL_VERSION_4_0)
    gl.min_sample_shading(0.5f);
    gl.get_min_sample_shading_value();
#endif
}
