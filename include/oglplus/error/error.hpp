/**
 *  @file oglplus/error/error.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ERROR_ERROR_1509260923_HPP
#define OGLPLUS_ERROR_ERROR_1509260923_HPP

#include <stdexcept>
#include "info.hpp"

namespace oglplus {

class error : public std::runtime_error {
private:
    error_info _info;

    static std::string _make_msg(error_info& info);

public:
    error(error_info&& info);

    const error_info& info() const noexcept {
        return _info;
    }
};

} // namespace oglplus

#include <oglplus/error/error.inl>

#endif // include guard
