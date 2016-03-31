/**
 *  @file oglplus/texgen/base_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
base_node::input_count(void)
{
	return 0u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
input_intf&
base_node::input(std::size_t)
{
	EAGINE_ABORT("Node does not have any inputs");
	input_intf* dummy = nullptr;
	assert(dummy != nullptr);
	return *dummy;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
base_node::output_count(void)
{
	return 0u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf&
base_node::output(std::size_t)
{
	EAGINE_ABORT("Node does not have any outputs");
	output_intf* dummy = nullptr;
	assert(dummy != nullptr);
	return *dummy;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_node::update_needed(void)
{
	for(std::size_t i=0, n=output_count(); i<n; ++i)
	{
		output(i).notify_connected();
	}
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
base_single_output_node::type_name(void)
{
	return single_output().type_name();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::size_t
base_single_output_node::output_count(void)
{
	return 1u;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
output_intf&
base_single_output_node::output(std::size_t index)
{
	(void)index;
	assert(index == 0);
	return single_output();
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

