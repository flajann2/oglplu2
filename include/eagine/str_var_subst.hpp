/**
 *  @file eagine/str_var_subst.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STR_VAR_SUBST_1509260923_HPP
#define EAGINE_STR_VAR_SUBST_1509260923_HPP

#include "config/basic.hpp"
#include <cassert>
#include <string>
#include <map>
#include <functional>

namespace eagine {

std::string
substitute_variables(
	const std::string& str,
	const std::function<std::string(const std::string&)>& translate
);

std::string
substitute_variables(
	const std::string& str,
	const std::map<std::string, std::string>& dictionary
);

class string_variable_map
{
private:
	std::map<std::string, std::string> _dict;
public:
	string_variable_map& set(std::string name, std::string value)
	{
		_dict.emplace(std::move(name), std::move(value));
		return *this;
	}

	std::string subst_variables(const std::string& str) const
	{
		return substitute_variables(str, _dict);
	}

	std::string operator()(const std::string& str) const
	{
		return substitute_variables(str, _dict);
	}
};

class environment_variable_map
{
private:
	static
	std::string _translate(const std::string&);
public:
	std::string subst_variables(const std::string& str) const
	{
		return substitute_variables(str, _translate);
	}

	std::string operator()(const std::string& str) const
	{
		return substitute_variables(str, _translate);
	}
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/str_var_subst.inl>
#endif

#endif // include guard
