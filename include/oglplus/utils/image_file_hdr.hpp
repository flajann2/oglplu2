/**
 *  @file oglplus/utils/image_file_hdr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_IMAGE_FILE_HDR_HPP
#define OGLPLUS_UTILS_IMAGE_FILE_HDR_HPP

#include <eagine/file_magic_number.hpp>
#include <eagine/memory/offset_span.hpp>
#include <eagine/valid_if/positive.hpp>
#include <array>

namespace oglplus {

struct image_data_header {
    eagine::file_magic_number<'o', 'g', 'l', '+', 't', 'e', 'x', 'i'> magic;
    GLsizei width{0}, height{0}, depth{0};
    GLenum format{GL_NONE}, internal_format{GL_NONE};
    GLenum data_type{GL_NONE};

    eagine::memory::offset_span<const GLubyte> pixels{};

    constexpr image_data_header() noexcept = default;

    image_data_header(
      eagine::valid_if_positive<GLsizei> w,
      eagine::valid_if_positive<GLsizei> h,
      eagine::valid_if_positive<GLsizei> d) noexcept
      : width(w.value())
      , height(h.value())
      , depth(d.value())
      , format(GL_NONE)
      , internal_format(GL_NONE)
      , data_type(GL_NONE)
      , pixels() {
    }
};

} // namespace oglplus

#endif // OGLPLUS_UTILS_IMAGE_FILE_HDR_HPP
