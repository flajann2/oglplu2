//  File test/boost_test/oglplus/enums/path_format_nv.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#include "common.hpp"
#define BOOST_TEST_MODULE OGLPLUS_path_format_nv

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_path_format_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_format_nv_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_format_nv x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_PATH_FORMAT_PS_NV
    x = ev.path_format_ps_nv;
    BOOST_CHECK(x == ev.path_format_ps_nv);
#ifdef GL_PATH_FORMAT_SVG_NV
    BOOST_CHECK(x != ev.path_format_svg_nv);
#endif
#endif

#ifdef GL_PATH_FORMAT_SVG_NV
    x = ev.path_format_svg_nv;
    BOOST_CHECK(x == ev.path_format_svg_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_format_nv_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_format_nv x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_PATH_FORMAT_PS_NV
    x = ev.path_format_ps_nv;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "PATH_FORMAT_PS_NV") == 0);
#endif

#ifdef GL_PATH_FORMAT_SVG_NV
    x = ev.path_format_svg_nv;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "PATH_FORMAT_SVG_NV") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_format_nv_range) {
    using namespace oglplus;
    auto count = enum_value_range<path_format_nv>().size();

#ifdef GL_PATH_FORMAT_PS_NV
    {
        --count;
        auto r = enum_value_range<path_format_nv>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), path_format_nv(GL_PATH_FORMAT_PS_NV)) !=
          r.end());
    }
#endif

#ifdef GL_PATH_FORMAT_SVG_NV
    {
        --count;
        auto r = enum_value_range<path_format_nv>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), path_format_nv(GL_PATH_FORMAT_SVG_NV)) !=
          r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_format_nv_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_format_nv x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_PATH_FORMAT_PS_NV
    x = ev.path_format_ps_nv;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.path_format_ps_nv);
#endif

#ifdef GL_PATH_FORMAT_SVG_NV
    x = ev.path_format_svg_nv;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.path_format_svg_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
