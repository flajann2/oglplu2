//  File test/boost_test/oalplus/enums/string_query.cpp
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
#include "common.hpp"
#define BOOST_TEST_MODULE OALPLUS_string_query

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_string_query_tests)

BOOST_AUTO_TEST_CASE(enum_string_query_values) {
    using namespace oalplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    string_query x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef AL_EXTENSIONS
    x = ev.extensions;
    BOOST_CHECK(x == ev.extensions);
#ifdef AL_RENDERER
    BOOST_CHECK(x != ev.renderer);
#endif
#ifdef AL_VENDOR
    BOOST_CHECK(x != ev.vendor);
#endif
#ifdef AL_VERSION
    BOOST_CHECK(x != ev.version);
#endif
#endif

#ifdef AL_RENDERER
    x = ev.renderer;
    BOOST_CHECK(x == ev.renderer);
#ifdef AL_VENDOR
    BOOST_CHECK(x != ev.vendor);
#endif
#ifdef AL_VERSION
    BOOST_CHECK(x != ev.version);
#endif
#endif

#ifdef AL_VENDOR
    x = ev.vendor;
    BOOST_CHECK(x == ev.vendor);
#ifdef AL_VERSION
    BOOST_CHECK(x != ev.version);
#endif
#endif

#ifdef AL_VERSION
    x = ev.version;
    BOOST_CHECK(x == ev.version);
#endif
}

BOOST_AUTO_TEST_CASE(enum_string_query_names) {
    using namespace oalplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    string_query x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef AL_EXTENSIONS
    x = ev.extensions;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "EXTENSIONS") == 0);
#endif

#ifdef AL_RENDERER
    x = ev.renderer;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "RENDERER") == 0);
#endif

#ifdef AL_VENDOR
    x = ev.vendor;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "VENDOR") == 0);
#endif

#ifdef AL_VERSION
    x = ev.version;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "VERSION") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_string_query_range) {
    using namespace oalplus;
    auto count = enum_value_range<string_query>().size();

#ifdef AL_EXTENSIONS
    {
        --count;
        auto r = enum_value_range<string_query>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), string_query(AL_EXTENSIONS)) !=
          r.end());
    }
#endif

#ifdef AL_RENDERER
    {
        --count;
        auto r = enum_value_range<string_query>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), string_query(AL_RENDERER)) != r.end());
    }
#endif

#ifdef AL_VENDOR
    {
        --count;
        auto r = enum_value_range<string_query>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), string_query(AL_VENDOR)) != r.end());
    }
#endif

#ifdef AL_VERSION
    {
        --count;
        auto r = enum_value_range<string_query>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), string_query(AL_VERSION)) != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_string_query_any) {
    using namespace oalplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    string_query x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

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

#include "../../unit_test_end.inl"
