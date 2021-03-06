/**
 *  @file oglplus/error/info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ERROR_INFO_HPP
#define OGLPLUS_ERROR_INFO_HPP

#include "../config/error.hpp"
#include "../object/gl_name.hpp"
#include "../utils/enum_class.hpp"
#include "../utils/indexed_enum.hpp"

#if !OGLPLUS_ERROR_NO_INFO_LOG
#include "../utils/string_span.hpp"
#include <string>
#endif

#if !OGLPLUS_ERROR_NO_EXTENDED_INFO
#include <memory>
#endif

namespace oglplus {

#if !OGLPLUS_ERROR_NO_EXTENDED_INFO
struct extended_error_info {
#if !OGLPLUS_ERROR_NO_SUBJECT
    any_object_name _sub_name;
#endif

#if !OGLPLUS_ERROR_NO_INFO_LOG
    std::string _info_log;
#endif

#if !OGLPLUS_ERROR_NO_IDENTIFIER
    std::string _identifier;
#endif

    extended_error_info() noexcept = default;
};
#endif

class error_info {
private:
    GLenum _gl_err_code;

#if !OGLPLUS_ERROR_NO_EXTENDED_INFO
    mutable std::unique_ptr<extended_error_info> _ext_info_ptr;

    extended_error_info& _ext_info() const noexcept;
#endif

#if !OGLPLUS_ERROR_NO_GL_LIB
    const char* _gl_lb_name;
#endif

#if !OGLPLUS_ERROR_NO_GL_FUNC
    const char* _gl_fn_name;
#endif

#if !OGLPLUS_ERROR_NO_SRC_FUNC
    const char* _src_func;
#endif

#if !OGLPLUS_ERROR_NO_SRC_FILE
    const char* _src_file;
#endif

#if !OGLPLUS_ERROR_NO_SRC_LINE
    unsigned _src_line;
#endif

#if !OGLPLUS_ERROR_NO_OBJECT
    any_object_name _obj_name;
#endif

#if !OGLPLUS_ERROR_NO_INDEX
    GLuint _index;
#endif

#if !OGLPLUS_ERROR_NO_ENUM_VALUE
    any_enum_value _enum_val;
#endif
public:
    static constexpr inline GLuint invalid_index() noexcept {
        return ~GLuint(0);
    }

    error_info(GLenum gl_err_code) noexcept;

    error_info() noexcept
      : error_info(GLenum(GL_NONE)) {
    }

    error_info& no_info() noexcept {
        return *this;
    }

    error_info& gl_error_code(GLenum gl_err_code) noexcept;

    GLenum gl_error_code() const noexcept;

    error_info& gl_library_name(const char* gl_lb_name) noexcept;

    const char* gl_library_name() const noexcept;

    error_info& gl_function_name(const char* gl_fn_name) noexcept;

    const char* gl_function_name() const noexcept;

    error_info& source_function(const char* src_func) noexcept;

    const char* source_function() const noexcept;

    error_info& source_file(const char* src_file) noexcept;

    const char* source_file() const noexcept;

    error_info& source_line(unsigned src_line) noexcept;

    unsigned source_line() const noexcept;

    error_info& gl_object_binding(
      const any_object_type& typ, const any_enum_value& tgt) noexcept;

    error_info& gl_object(const any_object_name& obj) noexcept;

    any_object_name gl_object() const noexcept;

    error_info& gl_subject_binding(
      const any_object_type& typ, const any_enum_value& tgt) noexcept;

    error_info& gl_subject(const any_object_name& sub) noexcept;

    any_object_name gl_subject() const noexcept;

    error_info& gl_index(GLuint idx) noexcept;

    GLuint gl_index() const noexcept;

    error_info& gl_enum_value(const any_enum_value& enum_val) noexcept;

    error_info& gl_enum_value(const any_indexed_enum_value& enum_val) noexcept;

    const any_enum_value& gl_enum_value() const noexcept;

    error_info& identifier(string_view log) noexcept;

    string_view identifier() const noexcept;

    error_info& info_log(string_view log) noexcept;

    error_info& info_log_of(const any_object_name& obj) noexcept;

    string_view info_log() const noexcept;
};

} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/error/info.inl>
#endif

#endif // OGLPLUS_ERROR_INFO_HPP
