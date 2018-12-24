//  File test/boost_test/eglplus/enums/opengl_rns.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_opengl_rns

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_opengl_rns_tests)

BOOST_AUTO_TEST_CASE(enum_opengl_rns_values) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    opengl_rns x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_LOSE_CONTEXT_ON_RESET
    x = ev.lose_context_on_reset;
    BOOST_CHECK(x == ev.lose_context_on_reset);
#ifdef EGL_NO_RESET_NOTIFICATION
    BOOST_CHECK(x != ev.no_reset_notification);
#endif
#endif

#ifdef EGL_NO_RESET_NOTIFICATION
    x = ev.no_reset_notification;
    BOOST_CHECK(x == ev.no_reset_notification);
#endif
}

BOOST_AUTO_TEST_CASE(enum_opengl_rns_names) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    opengl_rns x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_LOSE_CONTEXT_ON_RESET
    x = ev.lose_context_on_reset;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "LOSE_CONTEXT_ON_RESET") == 0);
#endif

#ifdef EGL_NO_RESET_NOTIFICATION
    x = ev.no_reset_notification;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "NO_RESET_NOTIFICATION") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_opengl_rns_range) {
    using namespace eglplus;
    auto count = enum_value_range<opengl_rns>().size();

#ifdef EGL_LOSE_CONTEXT_ON_RESET
    {
        --count;
        auto r = enum_value_range<opengl_rns>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), opengl_rns(EGL_LOSE_CONTEXT_ON_RESET)) !=
          r.end());
    }
#endif

#ifdef EGL_NO_RESET_NOTIFICATION
    {
        --count;
        auto r = enum_value_range<opengl_rns>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), opengl_rns(EGL_NO_RESET_NOTIFICATION)) !=
          r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_opengl_rns_any) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    opengl_rns x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef EGL_LOSE_CONTEXT_ON_RESET
    x = ev.lose_context_on_reset;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.lose_context_on_reset);
#endif

#ifdef EGL_NO_RESET_NOTIFICATION
    x = ev.no_reset_notification;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.no_reset_notification);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
