/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef UTILS_OGLPLUS_X11_GC_1107121519_HPP
#define UTILS_OGLPLUS_X11_GC_1107121519_HPP

#include "display.hpp"
#include "pixmap.hpp"

#include <X11/Xlib.h>
#include <stdexcept>

namespace oglplus {
namespace x11 {

class GC
 : public DisplayObject< ::GC>
{
public:
	GC(const Display& display, const Pixmap& pixmap)
	 : DisplayObject< ::GC>(
		display,
		::XCreateGC(display, pixmap, 0, NULL),
		::XFreeGC,
		"Error creating X GC (graphics context)"
	){ }
};

} // namespace x11
} // namespace oglplus

#endif // include guard
