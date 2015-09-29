//  File test/oglplus/enums/graphics_reset_status.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_graphics_reset_status

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_graphics_reset_status)

BOOST_AUTO_TEST_CASE(enum_graphics_reset_status_values)
{
	using namespace oglplus;
	enum_values ev;
	graphics_reset_status x;

#ifdef GL_GUILTY_CONTEXT_RESET
	x = ev.guilty_context_reset;
	BOOST_CHECK(x == ev.guilty_context_reset);
# ifdef GL_INNOCENT_CONTEXT_RESET
	BOOST_CHECK(x != ev.innocent_context_reset);
# endif
# ifdef GL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef GL_UNKNOWN_CONTEXT_RESET
	BOOST_CHECK(x != ev.unknown_context_reset);
# endif
#endif

#ifdef GL_INNOCENT_CONTEXT_RESET
	x = ev.innocent_context_reset;
# ifdef GL_GUILTY_CONTEXT_RESET
	BOOST_CHECK(x != ev.guilty_context_reset);
# endif
	BOOST_CHECK(x == ev.innocent_context_reset);
# ifdef GL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
# ifdef GL_UNKNOWN_CONTEXT_RESET
	BOOST_CHECK(x != ev.unknown_context_reset);
# endif
#endif

#ifdef GL_NO_ERROR
	x = ev.no_error;
# ifdef GL_GUILTY_CONTEXT_RESET
	BOOST_CHECK(x != ev.guilty_context_reset);
# endif
# ifdef GL_INNOCENT_CONTEXT_RESET
	BOOST_CHECK(x != ev.innocent_context_reset);
# endif
	BOOST_CHECK(x == ev.no_error);
# ifdef GL_UNKNOWN_CONTEXT_RESET
	BOOST_CHECK(x != ev.unknown_context_reset);
# endif
#endif

#ifdef GL_UNKNOWN_CONTEXT_RESET
	x = ev.unknown_context_reset;
# ifdef GL_GUILTY_CONTEXT_RESET
	BOOST_CHECK(x != ev.guilty_context_reset);
# endif
# ifdef GL_INNOCENT_CONTEXT_RESET
	BOOST_CHECK(x != ev.innocent_context_reset);
# endif
# ifdef GL_NO_ERROR
	BOOST_CHECK(x != ev.no_error);
# endif
	BOOST_CHECK(x == ev.unknown_context_reset);
#endif
}

BOOST_AUTO_TEST_SUITE_END()