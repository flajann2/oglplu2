/**
 *  @file oglplus/utils/image_file_io.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_IMAGE_FILE_IO_1509260923_HPP
#define OGLPLUS_UTILS_IMAGE_FILE_IO_1509260923_HPP

#include "image_file_hdr.hpp"
#include "memory_block.hpp"
#include <eagine/offset_ptr.hpp>
#include <iostream>

namespace oglplus {

inline
void write_and_pad_texture_image_data_header(
	std::ostream& output,
	image_data_header& header,
	std::size_t pixel_data_size
)
{
	std::size_t algn(alignof(image_data_header));

	assert(output.tellp() >= 0);
	while(std::size_t(output.tellp()) % algn != 0)
	{
		output.put('\0');
	}

	algn = 64;
	assert(sizeof(image_data_header) <= std::size_t(algn));

	eagine::memory::const_address hdraddr(&header);

	header.pixels = eagine::offset_array<const GLubyte>(
		static_cast<const GLubyte*>(hdraddr+std::ptrdiff_t(algn)),
		pixel_data_size
	);

	output.write(
		static_cast<const char*>(hdraddr),
		sizeof(header)
	);

	while(std::size_t(output.tellp()) % algn != 0)
	{
		output.put('\0');
	}
}

inline
void write_texture_image_data(
	std::ostream& output,
	image_data_header& header,
	const const_memory_block& pixels
)
{
	write_and_pad_texture_image_data_header(
		output,
		header,
		std::size_t(pixels.size())
	);

	output.write(
		reinterpret_cast<const char*>(pixels.data()),
		std::streamsize(pixels.size())
	);
}

} // namespace oglplus

#endif // include guard