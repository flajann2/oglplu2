/**
 *  @file oglplus/error/outcome.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_ERROR_OUTCOME_1509260923_HPP
#define OGLPLUS_ERROR_OUTCOME_1509260923_HPP

#include "../utils/outcome.hpp"
#include "info.hpp"

namespace oglplus {

template <typename T>
using outcome = basic_outcome<T, error_info>;

} // namespace oglplus

#endif // include guard
