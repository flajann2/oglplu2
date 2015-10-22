//  File test/oalplus/enums/string_query.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oalplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OALPLUS_string_query

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_string_query)

BOOST_AUTO_TEST_CASE(enum_string_query_values)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	string_query x;
	(void)x;

#ifdef AL_EXTENSIONS
	x = ev.extensions;
	BOOST_CHECK(x == ev.extensions);
# ifdef AL_RENDERER
	BOOST_CHECK(x != ev.renderer);
# endif
# ifdef AL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
# ifdef AL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef AL_RENDERER
	x = ev.renderer;
# ifdef AL_EXTENSIONS
	BOOST_CHECK(x != ev.extensions);
# endif
	BOOST_CHECK(x == ev.renderer);
# ifdef AL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
# ifdef AL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef AL_VENDOR
	x = ev.vendor;
# ifdef AL_EXTENSIONS
	BOOST_CHECK(x != ev.extensions);
# endif
# ifdef AL_RENDERER
	BOOST_CHECK(x != ev.renderer);
# endif
	BOOST_CHECK(x == ev.vendor);
# ifdef AL_VERSION
	BOOST_CHECK(x != ev.version);
# endif
#endif

#ifdef AL_VERSION
	x = ev.version;
# ifdef AL_EXTENSIONS
	BOOST_CHECK(x != ev.extensions);
# endif
# ifdef AL_RENDERER
	BOOST_CHECK(x != ev.renderer);
# endif
# ifdef AL_VENDOR
	BOOST_CHECK(x != ev.vendor);
# endif
	BOOST_CHECK(x == ev.version);
#endif
}

BOOST_AUTO_TEST_CASE(enum_string_query_names)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	string_query x;
	(void)x;

#ifdef AL_EXTENSIONS
	x = ev.extensions;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EXTENSIONS"
	) == 0);
#endif

#ifdef AL_RENDERER
	x = ev.renderer;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RENDERER"
	) == 0);
#endif

#ifdef AL_VENDOR
	x = ev.vendor;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VENDOR"
	) == 0);
#endif

#ifdef AL_VERSION
	x = ev.version;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERSION"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_string_query_range)
{
	using namespace oalplus;
	string_query x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef AL_EXTENSIONS
{
	--count;
	array_view<const ALenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		AL_EXTENSIONS
	) != r.end());
}
#endif

#ifdef AL_RENDERER
{
	--count;
	array_view<const ALenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		AL_RENDERER
	) != r.end());
}
#endif

#ifdef AL_VENDOR
{
	--count;
	array_view<const ALenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		AL_VENDOR
	) != r.end());
}
#endif

#ifdef AL_VERSION
{
	--count;
	array_view<const ALenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		AL_VERSION
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_string_query_any)
{
	using namespace oalplus;
	enum_values ev;
	(void)ev;
	string_query x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef AL_EXTENSIONS
	x = ev.extensions;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.extensions);
#endif

#ifdef AL_RENDERER
	x = ev.renderer;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.renderer);
#endif

#ifdef AL_VENDOR
	x = ev.vendor;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vendor);
#endif

#ifdef AL_VERSION
	x = ev.version;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.version);
#endif
}

BOOST_AUTO_TEST_SUITE_END()