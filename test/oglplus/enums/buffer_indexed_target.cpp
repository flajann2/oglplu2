//  File test/oglplus/enums/buffer_indexed_target.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_buffer_indexed_target

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_buffer_indexed_target)

BOOST_AUTO_TEST_CASE(enum_buffer_indexed_target_values)
{
	using namespace oglplus;
	enum_values ev;
	buffer_indexed_target x;

#ifdef GL_ATOMIC_COUNTER_BUFFER
	x = ev.atomic_counter_buffer;
	BOOST_CHECK(x == ev.atomic_counter_buffer);
# ifdef GL_SHADER_STORAGE_BUFFER
	BOOST_CHECK(x != ev.shader_storage_buffer);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	BOOST_CHECK(x != ev.transform_feedback_buffer);
# endif
# ifdef GL_UNIFORM_BUFFER
	BOOST_CHECK(x != ev.uniform_buffer);
# endif
#endif

#ifdef GL_SHADER_STORAGE_BUFFER
	x = ev.shader_storage_buffer;
# ifdef GL_ATOMIC_COUNTER_BUFFER
	BOOST_CHECK(x != ev.atomic_counter_buffer);
# endif
	BOOST_CHECK(x == ev.shader_storage_buffer);
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	BOOST_CHECK(x != ev.transform_feedback_buffer);
# endif
# ifdef GL_UNIFORM_BUFFER
	BOOST_CHECK(x != ev.uniform_buffer);
# endif
#endif

#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	x = ev.transform_feedback_buffer;
# ifdef GL_ATOMIC_COUNTER_BUFFER
	BOOST_CHECK(x != ev.atomic_counter_buffer);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER
	BOOST_CHECK(x != ev.shader_storage_buffer);
# endif
	BOOST_CHECK(x == ev.transform_feedback_buffer);
# ifdef GL_UNIFORM_BUFFER
	BOOST_CHECK(x != ev.uniform_buffer);
# endif
#endif

#ifdef GL_UNIFORM_BUFFER
	x = ev.uniform_buffer;
# ifdef GL_ATOMIC_COUNTER_BUFFER
	BOOST_CHECK(x != ev.atomic_counter_buffer);
# endif
# ifdef GL_SHADER_STORAGE_BUFFER
	BOOST_CHECK(x != ev.shader_storage_buffer);
# endif
# ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	BOOST_CHECK(x != ev.transform_feedback_buffer);
# endif
	BOOST_CHECK(x == ev.uniform_buffer);
#endif
}

BOOST_AUTO_TEST_SUITE_END()