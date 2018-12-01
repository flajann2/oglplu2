//  File test/boost_test/eglplus/enums/texture_format.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/eglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#include "common.hpp"
#define BOOST_TEST_MODULE EGLPLUS_texture_format

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_texture_format_tests)

BOOST_AUTO_TEST_CASE(enum_texture_format_values) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    texture_format x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_NO_TEXTURE
    x = ev.no_texture;
    BOOST_CHECK(x == ev.no_texture);
#ifdef EGL_TEXTURE_RGB
    BOOST_CHECK(x != ev.texture_rgb);
#endif
#ifdef EGL_TEXTURE_RGBA
    BOOST_CHECK(x != ev.texture_rgba);
#endif
#endif

#ifdef EGL_TEXTURE_RGB
    x = ev.texture_rgb;
    BOOST_CHECK(x == ev.texture_rgb);
#ifdef EGL_TEXTURE_RGBA
    BOOST_CHECK(x != ev.texture_rgba);
#endif
#endif

#ifdef EGL_TEXTURE_RGBA
    x = ev.texture_rgba;
    BOOST_CHECK(x == ev.texture_rgba);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_format_names) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    texture_format x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_NO_TEXTURE
    x = ev.no_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "NO_TEXTURE") == 0);
#endif

#ifdef EGL_TEXTURE_RGB
    x = ev.texture_rgb;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "TEXTURE_RGB") == 0);
#endif

#ifdef EGL_TEXTURE_RGBA
    x = ev.texture_rgba;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "TEXTURE_RGBA") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_texture_format_range) {
    using namespace eglplus;
    auto count = enum_value_range<texture_format>().size();

#ifdef EGL_NO_TEXTURE
    {
        --count;
        auto r = enum_value_range<texture_format>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), texture_format(EGL_NO_TEXTURE)) !=
          r.end());
    }
#endif

#ifdef EGL_TEXTURE_RGB
    {
        --count;
        auto r = enum_value_range<texture_format>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), texture_format(EGL_TEXTURE_RGB)) !=
          r.end());
    }
#endif

#ifdef EGL_TEXTURE_RGBA
    {
        --count;
        auto r = enum_value_range<texture_format>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), texture_format(EGL_TEXTURE_RGBA)) !=
          r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_texture_format_any) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    texture_format x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef EGL_NO_TEXTURE
    x = ev.no_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.no_texture);
#endif

#ifdef EGL_TEXTURE_RGB
    x = ev.texture_rgb;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_rgb);
#endif

#ifdef EGL_TEXTURE_RGBA
    x = ev.texture_rgba;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_rgba);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
