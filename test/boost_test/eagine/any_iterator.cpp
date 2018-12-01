/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/any_iterator.hpp>
#define BOOST_TEST_MODULE EAGINE_any_iterator
#include "../unit_test_begin.inl"

#include <algorithm>
#include <set>
#include <vector>

BOOST_AUTO_TEST_SUITE(any_iterator_tests)

static eagine::test_random_generator rg;

template <typename T>
void
test_any_iterator_1_I(
  const eagine::any_std_forward_iterator<T>& b,
  const eagine::any_std_forward_iterator<T>& e) {
    std::vector<T> v(b, e);

    BOOST_CHECK(std::equal(b, e, v.begin()));
}

template <typename T>
void
test_any_iterator_1_T(void) {
    std::set<T> s;
    const int n = rg.get_int(10, 100);

    for(int i = 0; i < n; ++i) {
        s.insert(rg.get_any<T>());
    }

    test_any_iterator_1_I<T>(s.begin(), s.end());
}

BOOST_AUTO_TEST_CASE(any_iterator_1) {
    test_any_iterator_1_T<int>();
    test_any_iterator_1_T<float>();
    test_any_iterator_1_T<double>();
}

template <typename T>
void
test_any_iterator_2_T(void) {
    using namespace eagine;

    std::vector<T> vec(rg.get<std::size_t>(10, 100));

    any_std_forward_iterator<T> b = vec.begin();
    any_std_forward_iterator<T> e = vec.end();

    T tmp = T(0);
    for(T& val : vec) {
        val = tmp++;
    }

    tmp = T(0);
    for(auto i = b; i != e; ++i, ++tmp) {
        BOOST_CHECK_EQUAL(*i, tmp);
    }

    tmp = T(0);
    for(auto i = b; i != e; i++, ++tmp) {
        BOOST_CHECK_EQUAL(*i, tmp);
    }
}

BOOST_AUTO_TEST_CASE(any_iterator_2) {
    test_any_iterator_2_T<short>();
    test_any_iterator_2_T<int>();
    test_any_iterator_2_T<unsigned>();
}

template <typename T>
void
test_any_iterator_3_T(void) {
    using namespace eagine;

    std::vector<T> vec(rg.get<std::size_t>(10, 100));

    any_std_forward_range<T> rng = vec;

    T tmp = T(0);
    for(T& val : vec) {
        val = tmp++;
    }

    tmp = T(0);
    for(const T& val : rng) {
        BOOST_CHECK_EQUAL(val, tmp);
        ++tmp;
    }

    tmp = T(0);
    for(const T& val : rng) {
        BOOST_CHECK_EQUAL(val, tmp);
        ++tmp;
    }
}

BOOST_AUTO_TEST_CASE(any_iterator_3) {
    test_any_iterator_3_T<short>();
    test_any_iterator_3_T<int>();
    test_any_iterator_3_T<unsigned>();
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
