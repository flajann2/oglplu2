//  File test/boost_test/eglplus/enums/swap_behavior.cpp
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
#define BOOST_TEST_MODULE EGLPLUS_swap_behavior

#include "../../unit_test_begin.inl"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_swap_behavior_tests)

BOOST_AUTO_TEST_CASE(enum_swap_behavior_values) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    swap_behavior x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_BUFFER_DESTROYED
    x = ev.buffer_destroyed;
    BOOST_CHECK(x == ev.buffer_destroyed);
#ifdef EGL_BUFFER_PRESERVED
    BOOST_CHECK(x != ev.buffer_preserved);
#endif
#endif

#ifdef EGL_BUFFER_PRESERVED
    x = ev.buffer_preserved;
    BOOST_CHECK(x == ev.buffer_preserved);
#endif
}

BOOST_AUTO_TEST_CASE(enum_swap_behavior_names) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    swap_behavior x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef EGL_BUFFER_DESTROYED
    x = ev.buffer_destroyed;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "BUFFER_DESTROYED") == 0);
#endif

#ifdef EGL_BUFFER_PRESERVED
    x = ev.buffer_preserved;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "BUFFER_PRESERVED") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_swap_behavior_range) {
    using namespace eglplus;
    auto count = enum_value_range<swap_behavior>().size();

#ifdef EGL_BUFFER_DESTROYED
    {
        --count;
        auto r = enum_value_range<swap_behavior>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), swap_behavior(EGL_BUFFER_DESTROYED)) !=
          r.end());
    }
#endif

#ifdef EGL_BUFFER_PRESERVED
    {
        --count;
        auto r = enum_value_range<swap_behavior>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), swap_behavior(EGL_BUFFER_PRESERVED)) !=
          r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_swap_behavior_any) {
    using namespace eglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    swap_behavior x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef EGL_BUFFER_DESTROYED
    x = ev.buffer_destroyed;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.buffer_destroyed);
#endif

#ifdef EGL_BUFFER_PRESERVED
    x = ev.buffer_preserved;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.buffer_preserved);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
