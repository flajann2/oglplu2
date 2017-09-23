/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/maybe_unused.hpp>
#include <oglplus/gl_fixed.hpp>
#include <oglplus/operations.hpp>

using namespace oglplus;

void oglplus_numeric_queries_test(void)
{
	using namespace oglplus;

	oper::numeric_queries gl;

	gl.get_integer_v(
		binding_query(GL_DRAW_FRAMEBUFFER_BINDING),
		span<GLint>()
	);

	gl.get_boolean_v(
		numeric_query(GL_DEPTH_TEST),
		span<GLboolean>()
	);
	gl.get_boolean(numeric_query(GL_DEPTH_TEST));

	gl.get_integer_v(
		numeric_query(GL_ACTIVE_TEXTURE),
		span<GLint>()
	);
	gl.get_integer(numeric_query(GL_ACTIVE_TEXTURE));

#if defined(GL_VERSION_3_2)
	gl.get_integer64_v(
		numeric_query(GL_SHADER_STORAGE_BUFFER_START),
		span<GLint64>()
	);
	gl.get_integer64(numeric_query(GL_SHADER_STORAGE_BUFFER_START));
#endif

	gl.get_float_v(
		numeric_query(GL_MAX_TEXTURE_LOD_BIAS),
		span<GLfloat>()
	);
	gl.get_float(numeric_query(GL_MAX_TEXTURE_LOD_BIAS));

#if defined(GLdouble)
	gl.get_double_v(
		numeric_query(GL_MAX_TEXTURE_LOD_BIAS),
		span<GLdouble>()
	);
	gl.get_double(numeric_query(GL_MAX_TEXTURE_LOD_BIAS));
#endif

#if defined(GL_VERSION_3_2)
	gl.get_boolean_v(
		numeric_query(GL_DEPTH_TEST),
		0,
		span<GLboolean>()
	);
	gl.get_boolean(numeric_query(GL_DEPTH_TEST), 0);

	gl.get_integer_v(
		numeric_query(GL_ACTIVE_TEXTURE),
		0,
		span<GLint>()
	);
	gl.get_integer(numeric_query(GL_ACTIVE_TEXTURE), 0);

	gl.get_integer64_v(
		numeric_query(GL_SHADER_STORAGE_BUFFER_START),
		0,
		span<GLint64>()
	);
	gl.get_integer64(numeric_query(GL_SHADER_STORAGE_BUFFER_START), 0);
#endif

#if defined(GL_VERSION_4_1)
	gl.get_float_v(
		numeric_query(GL_MAX_TEXTURE_LOD_BIAS),
		0,
		span<GLfloat>()
	);
	gl.get_float(numeric_query(GL_MAX_TEXTURE_LOD_BIAS), 0);

	gl.get_double_v(
		numeric_query(GL_MAX_TEXTURE_LOD_BIAS),
		0,
		span<GLdouble>()
	);
	gl.get_double(numeric_query(GL_MAX_TEXTURE_LOD_BIAS), 0);
#endif
}

void oglplus_synchronization_test(void)
{
	using namespace oglplus;

	oper::synchronization gl;

#if defined(GL_VERSION_4_2) || defined(GL_ARB_shader_image_load_store)
	gl.memory_barrier(enum_bitfield<memory_barrier_bits>(0));
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

void oglplus_buffer_clearing_state_test(void)
{
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

void oglplus_buffer_clearing_ops_test(void)
{
	using namespace oglplus;

	oper::buffer_clearing_ops gl;

	gl.clear(enum_bitfield<buffer_select_bits>(0));
}

void oglplus_capability_state_test(void)
{
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
}

void oglplus_compatibility_drawing_test(void)
{
	using namespace oglplus;

#if defined(GL_ARB_compatibility)
	oper::compatibility_drawing gl;

	gl.begin(old_primitive_type(GL_QUADS));
	gl.end();

	// vertex
	gl.vertex_s(0, 1);
	gl.vertex_s(0, 1, 2);
	gl.vertex_s(0, 1, 2, 1);
	gl.vertex(std::array<GLshort, 4>{{0, 1, 2, 1}});

	gl.vertex_i(0, 1);
	gl.vertex_i(0, 1, 2);
	gl.vertex_i(0, 1, 2, 1);
	gl.vertex(std::array<GLint, 4>{{0, 1, 2, 1}});

	gl.vertex_f(0.f, 1.f);
	gl.vertex_f(0.f, 1.f, 2.f);
	gl.vertex_f(0.f, 1.f, 2.f, 1.f);
	gl.vertex(std::array<GLfloat, 4>{{0.f, 1.f, 2.f, 1.f}});

	gl.vertex_d(0.0, 1.0);
	gl.vertex_d(0.0, 1.0, 2.0);
	gl.vertex_d(0.0, 1.0, 2.0, 1.0);
	gl.vertex(std::array<GLdouble, 4>{{0.0, 1.0, 2.0, 1.0}});

	// color
	gl.color_ub(0x00, 0x00, 0x00);
	gl.color_ub(0x00, 0x00, 0x00, 0x00);
	gl.color(std::array<GLubyte, 4>{{0x00, 0x00, 0x00, 0x00}});

	gl.color_i(0, 0, 0);
	gl.color_i(0, 0, 0, 1);
	gl.color(std::array<GLint, 4>{{0, 0, 0, 1}});

	gl.color_f(0.f, 0.f, 0.f);
	gl.color_f(0.f, 0.f, 0.f, 0.f);
	gl.color(std::array<GLfloat, 4>{{0.f, 0.f, 0.f, 0.f}});

	gl.color_d(0.0, 0.0, 0.0);
	gl.color_d(0.0, 0.0, 0.0, 0.0);
	gl.color(std::array<GLdouble, 4>{{0.0, 0.0, 0.0, 0.0}});

	// tex_coord
	gl.tex_coord_s(0, 1);
	gl.tex_coord_s(0, 1, 2);
	gl.tex_coord_s(0, 1, 2, 1);
	gl.tex_coord(std::array<GLshort, 4>{{0, 1, 2, 1}});

	gl.tex_coord_i(0, 1);
	gl.tex_coord_i(0, 1, 2);
	gl.tex_coord_i(0, 1, 2, 1);
	gl.tex_coord(std::array<GLint, 4>{{0, 1, 2, 1}});

	gl.tex_coord_f(0.f, 1.f);
	gl.tex_coord_f(0.f, 1.f, 2.f);
	gl.tex_coord_f(0.f, 1.f, 2.f, 1.f);
	gl.tex_coord(std::array<GLfloat, 4>{{0.f, 1.f, 2.f, 1.f}});

	gl.tex_coord_d(0.0, 1.0);
	gl.tex_coord_d(0.0, 1.0, 2.0);
	gl.tex_coord_d(0.0, 1.0, 2.0, 1.0);
	gl.tex_coord(std::array<GLdouble, 4>{{0.0, 1.0, 2.0, 1.0}});

#endif
}

void oglplus_compatibility_matrix_test(void)
{
	using namespace oglplus;

#if defined(GL_ARB_compatibility)
	oper::compatibility_matrix gl;

	std::array<GLfloat, 16> matfa{{
		1.f, 0.f, 0.f, 0.f,
		0.f, 1.f, 0.f, 0.f,
		0.f, 0.f, 1.f, 0.f,
		0.f, 0.f, 0.f, 1.f
	}};
	span<GLfloat> matf = matfa;

	std::array<GLdouble, 16> matda{{
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	}};
	span<GLdouble> matd = matda;

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
		old_matrix_mode(GL_PROJECTION),
		degrees_t<GLfloat>(0.f), 1.f, 0.f, 0.f
	);
#endif

	gl.rotate_d(degrees_t<GLfloat>(0.0), 1.0, 0.0, 0.0);
#ifdef GL_EXT_direct_state_access
	gl.rotate_d(
		old_matrix_mode(GL_PROJECTION),
		degrees_t<GLfloat>(0.0), 1.0, 0.0, 0.0
	);
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

