/**
 *  @file eagine/config/basic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_CONFIG_BASIC_HPP
#define EAGINE_CONFIG_BASIC_HPP

#if __has_include(<eagine/config/site.hpp>)
#include <eagine/config/site.hpp>
#endif

#ifndef EAGINE_LOW_PROFILE
#define EAGINE_LOW_PROFILE 0
#endif

#ifndef EAGINE_LINK_LIBRARY
#define EAGINE_LINK_LIBRARY 0
#endif

#if EAGINE_LINK_LIBRARY
#define EAGINE_LIB_FUNC
#else
#define EAGINE_LIB_FUNC inline
#endif

#endif // EAGINE_CONFIG_BASIC_HPP
