//  File test/boost_test/oglplus/enums/path_color_format_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_color_format_nv

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_path_color_format_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_color_format_nv_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_color_format_nv x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_ALPHA
    x = ev.alpha;
    BOOST_CHECK(x == ev.alpha);
#ifdef GL_INTENSITY
    BOOST_CHECK(x != ev.intensity);
#endif
#ifdef GL_LUMINANCE
    BOOST_CHECK(x != ev.luminance);
#endif
#ifdef GL_LUMINANCE_ALPHA
    BOOST_CHECK(x != ev.luminance_alpha);
#endif
#ifdef GL_RGB
    BOOST_CHECK(x != ev.rgb);
#endif
#ifdef GL_RGBA
    BOOST_CHECK(x != ev.rgba);
#endif
#endif

#ifdef GL_INTENSITY
    x = ev.intensity;
    BOOST_CHECK(x == ev.intensity);
#ifdef GL_LUMINANCE
    BOOST_CHECK(x != ev.luminance);
#endif
#ifdef GL_LUMINANCE_ALPHA
    BOOST_CHECK(x != ev.luminance_alpha);
#endif
#ifdef GL_RGB
    BOOST_CHECK(x != ev.rgb);
#endif
#ifdef GL_RGBA
    BOOST_CHECK(x != ev.rgba);
#endif
#endif

#ifdef GL_LUMINANCE
    x = ev.luminance;
    BOOST_CHECK(x == ev.luminance);
#ifdef GL_LUMINANCE_ALPHA
    BOOST_CHECK(x != ev.luminance_alpha);
#endif
#ifdef GL_RGB
    BOOST_CHECK(x != ev.rgb);
#endif
#ifdef GL_RGBA
    BOOST_CHECK(x != ev.rgba);
#endif
#endif

#ifdef GL_LUMINANCE_ALPHA
    x = ev.luminance_alpha;
    BOOST_CHECK(x == ev.luminance_alpha);
#ifdef GL_RGB
    BOOST_CHECK(x != ev.rgb);
#endif
#ifdef GL_RGBA
    BOOST_CHECK(x != ev.rgba);
#endif
#endif

#ifdef GL_RGB
    x = ev.rgb;
    BOOST_CHECK(x == ev.rgb);
#ifdef GL_RGBA
    BOOST_CHECK(x != ev.rgba);
#endif
#endif

#ifdef GL_RGBA
    x = ev.rgba;
    BOOST_CHECK(x == ev.rgba);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_color_format_nv_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_color_format_nv x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_ALPHA
    x = ev.alpha;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "ALPHA") == 0);
#endif

#ifdef GL_INTENSITY
    x = ev.intensity;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "INTENSITY") == 0);
#endif

#ifdef GL_LUMINANCE
    x = ev.luminance;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "LUMINANCE") == 0);
#endif

#ifdef GL_LUMINANCE_ALPHA
    x = ev.luminance_alpha;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "LUMINANCE_ALPHA") == 0);
#endif

#ifdef GL_RGB
    x = ev.rgb;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "RGB") == 0);
#endif

#ifdef GL_RGBA
    x = ev.rgba;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "RGBA") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_color_format_nv_range) {
    using namespace oglplus;
    auto count = enum_value_range<path_color_format_nv>().size();

#ifdef GL_ALPHA
    {
        --count;
        auto r = enum_value_range<path_color_format_nv>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), path_color_format_nv(GL_ALPHA)) !=
          r.end());
    }
#endif

#ifdef GL_INTENSITY
    {
        --count;
        auto r = enum_value_range<path_color_format_nv>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), path_color_format_nv(GL_INTENSITY)) !=
          r.end());
    }
#endif

#ifdef GL_LUMINANCE
    {
        --count;
        auto r = enum_value_range<path_color_format_nv>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), path_color_format_nv(GL_LUMINANCE)) !=
          r.end());
    }
#endif

#ifdef GL_LUMINANCE_ALPHA
    {
        --count;
        auto r = enum_value_range<path_color_format_nv>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), path_color_format_nv(GL_LUMINANCE_ALPHA)) !=
          r.end());
    }
#endif

#ifdef GL_RGB
    {
        --count;
        auto r = enum_value_range<path_color_format_nv>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), path_color_format_nv(GL_RGB)) !=
          r.end());
    }
#endif

#ifdef GL_RGBA
    {
        --count;
        auto r = enum_value_range<path_color_format_nv>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), path_color_format_nv(GL_RGBA)) !=
          r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_color_format_nv_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    path_color_format_nv x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_ALPHA
    x = ev.alpha;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.alpha);
#endif

#ifdef GL_INTENSITY
    x = ev.intensity;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.intensity);
#endif

#ifdef GL_LUMINANCE
    x = ev.luminance;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.luminance);
#endif

#ifdef GL_LUMINANCE_ALPHA
    x = ev.luminance_alpha;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.luminance_alpha);
#endif

#ifdef GL_RGB
    x = ev.rgb;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.rgb);
#endif

#ifdef GL_RGBA
    x = ev.rgba;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.rgba);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
