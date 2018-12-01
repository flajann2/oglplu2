/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEST_EAGINE_HELPER_OBJECT_C_HPP
#define TEST_EAGINE_HELPER_OBJECT_C_HPP

#include <cassert>
#include <utility>

template <typename ObjectName>
void
eagine_object_name_test(void) {
    ObjectName n1;
    assert(!n1 == true);
    assert(bool(n1) == false);

    ObjectName n2(0);
    assert(!n2 == false);
    assert(bool(n2) == true);

    ObjectName n3(n1);
    assert(!n3 == true);
    assert(bool(n3) == false);

    ObjectName n4(std::move(n2));
    assert(!n2 == true);
    assert(bool(n2) == false);
    assert(!n4 == false);
    assert(bool(n4) == true);
}

template <typename Object>
void
eagine_do_test_object(Object& o1) {
    assert(!o1 == false);
    assert(bool(o1) == true);

    Object o2(std::move(o1));
    assert(!o2 == false);
    assert(bool(o2) == true);
    assert(!o1 == true);
    assert(bool(o1) == false);
}

template <typename Object>
void
eagine_object_test(void) {
    Object o1;
    eagine_do_test_object(o1);
}

template <typename Object, typename ObjectType>
void
eagine_object_test(ObjectType type) {
    Object o1(type);
    eagine_do_test_object(o1);
}

// TODO

#endif // include guard
