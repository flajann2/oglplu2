/**
 *  @file eagine/posix/error.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_ERROR_1509260923_HPP
#define EAGINE_POSIX_ERROR_1509260923_HPP

#include <system_error>
#include <cerrno>
#include "../outcome.hpp"

namespace eagine {
namespace posix {

struct error_info {
    int error_code;
    int file_desc;

    constexpr error_info(int code, int fd) noexcept
      : error_code(code)
      , file_desc(fd) {
    }

    constexpr error_info() noexcept
      : error_code(0)
      , file_desc(-1) {
    }
};

struct error_handling_policy {
    static bool is_valid(const error_info& info) noexcept {
        return info.error_code != 0;
    }

    [[noreturn]] static void invoke(const error_info& info) {
        throw std::system_error(info.error_code, std::system_category());
    }

    static void cancel(error_info& info) noexcept {
        info.error_code = 0;
    }
};

template <typename T>
using outcome = basic_outcome<T, error_info, error_handling_policy>;

static inline outcome<void>
error_outcome(int fd) noexcept {
    return outcome<void>(error_info(errno, fd));
}

static inline outcome<void>
error_if(bool is_error, int fd) noexcept {
    return is_error ? error_outcome(fd) : outcome<void>();
}

static inline outcome<void>
error_if_not_zero(int result, int fd) noexcept {
    return error_if(result != 0, fd);
}

template <typename T>
static inline outcome<T>
error_if_negative(T result, int fd) noexcept {
    return (result < T(0)) ? outcome<T>(error_info(errno, fd))
                           : outcome<T>(result);
}

template <typename T>
static inline outcome<T>
error_if_negative(T result) noexcept {
    return error_if_negative(result, -1);
}

} // namespace posix
} // namespace eagine

#endif // include guard
