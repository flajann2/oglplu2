/**
 *  .file oglplus/example/state_view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_STATE_VIEW_1512120710_HPP
#define OGLPLUS_EXAMPLE_STATE_VIEW_1512120710_HPP

#include <eagine/valid_if/decl.hpp>
#include <eagine/valid_if/positive.hpp>
#include <oglplus/utils/quantities.hpp>
#include <cassert>

namespace oglplus {

template <typename T>
class example_state_variable_base
{
protected:
	T _old_value;
	T _new_value;

	bool _update_value(const T& new_value)
	noexcept {
		_old_value = _new_value;

		if(_new_value != new_value) {
			_new_value =  new_value;
			return true;
		}
		return false;
	}

	bool _advance_value(const T& delta_value)
	noexcept {
		_old_value = _new_value;
		_new_value += delta_value;
		return true;
	}


	example_state_variable_base(void) = default;

	constexpr inline explicit
	example_state_variable_base(const T& initial)
	noexcept
	 : _old_value(initial)
	 , _new_value(initial)
	{ }
public:
	constexpr inline
	example_state_variable_base(const T& old_val, const T& new_val)
	noexcept
	 : _old_value(old_val)
	 , _new_value(new_val)
	{ }

	void sync(void)
	noexcept { _old_value = _new_value; }

	const T& value(void) const
	noexcept { return _new_value; }

	const T& old_value(void) const
	noexcept { return _old_value; }

	const T& value(bool old) const
	noexcept { return old ? old_value() : value(); }

	T delta(void) const
	noexcept { return value() - old_value(); }

	operator T (void) const
	noexcept { return value(); }

	template <typename U, typename ... P>
	operator eagine::valid_if<U, P...> (void) const
	noexcept { return {U(value())}; }

	template <typename U>
	example_state_variable_base<U> as(void) const
	noexcept { return {U(_old_value), U(_new_value)}; }
};

template <typename T1, typename T2>
static inline
example_state_variable_base<decltype(std::declval<T1>()/std::declval<T2>())>
operator / (
	const example_state_variable_base<T1>& v1,
	const example_state_variable_base<T2>& v2
) noexcept {
	return {v1.old_value()/v2.old_value(), v1.value()/v2.value()};
}

template <typename T>
class example_state_variable;

template <typename T>
class example_state_variable
 : public example_state_variable_base<T> {
public:
	constexpr inline
	example_state_variable(const T& initial)
	noexcept
	 : example_state_variable_base<T>(initial)
	{ }

	bool assign(const T& new_value) {
		return this->_update_value(new_value);
	}

	bool advance(const T& delta_value) {
		return this->_advance_value(delta_value);
	}
};

template <typename T, typename ... P>
class example_state_variable<eagine::valid_if<T, P...>>
 : public example_state_variable_base<T> {
public:
	constexpr inline
	example_state_variable(const eagine::valid_if<T, P...>& initial)
	noexcept
	 : example_state_variable_base<T>(initial.value())
	{ }

	bool assign(const eagine::valid_if<T, P...>& new_value) {
		return this->_update_value(new_value.value());
	}

	bool advance(const eagine::valid_if<T, P...>& delta_value) {
		return this->_advance_value(delta_value.value());
	}
};

class example_state_view {

protected:
	static constexpr const bool _old = true;

	example_state_variable<eagine::valid_if_positive<int>> _width;
	example_state_variable<eagine::valid_if_positive<int>> _height;
	example_state_variable<eagine::valid_if_positive<int>> _depth;

	example_state_variable<int> _mouse_x;
	example_state_variable<int> _mouse_y;
	example_state_variable<int> _mouse_z;

	example_state_variable<float> _exe_time;
	float _usr_act_time;

	bool _notice_user_activity(bool something_changed = true)
	noexcept;

	int _frame_no;

	int _x_tiles, _tile_i;
	int _y_tiles, _tile_j;


	bool _old_mouse_btn_1 : 1;
	bool _new_mouse_btn_1 : 1;
	bool _old_mouse_btn_2 : 1;
	bool _new_mouse_btn_2 : 1;
	bool _old_mouse_btn_3 : 1;
	bool _new_mouse_btn_3 : 1;
	bool _old_mouse_btn_4 : 1;
	bool _new_mouse_btn_4 : 1;

	bool _mouse_btn(int i, bool old = false) const
	noexcept;

	void _set_mouse_btn(int i, bool state)
	noexcept;

	bool _old_user_idle : 1;
	bool _new_user_idle : 1;

	example_state_view(void)
	noexcept;
public:
	const auto& width(void) const
	noexcept { return _width; }

	const auto& height(void) const
	noexcept { return _height; }

	const auto& depth(void) const
	noexcept { return _depth; }

	const auto& mouse_x(void) const
	noexcept { return _mouse_x; }

	const auto& mouse_y(void) const
	noexcept { return _mouse_y; }

	const auto& mouse_z(void) const
	noexcept { return _mouse_z; }

	auto aspect(void) const
	noexcept {
		return width().as<float>()/height().as<float>();
	}

	seconds_t<float> exec_time(void) const
	noexcept {
		return seconds_(_exe_time.value());
	}

	seconds_t<float> user_activity_time(void) const
	noexcept {
		return seconds_(_usr_act_time);
	}

	seconds_t<float> user_idle_time(void) const
	noexcept {
		return exec_time() - user_activity_time();
	}

	bool user_idle(bool old = false) const
	noexcept {
		return old?_old_user_idle:_new_user_idle;
	}

	bool user_became_idle(void) const
	noexcept {
		return !user_idle(_old) && user_idle();
	}

	bool user_became_active(void) const
	noexcept {
		return user_idle(_old) && !user_idle();
	}

	seconds_t<float> frame_duration(void) const
	noexcept {
		return seconds_(_exe_time.delta());
	}

	int frame_number(void) const
	noexcept { return _frame_no; }

	int x_tiles(void) const
	noexcept { return _x_tiles; }

	int tile_i(void) const
	noexcept {
		assert(_tile_i < _x_tiles);
		return _tile_i;
	}

	int tile_w(void) const
	noexcept {
		return (width()/x_tiles())+((tile_i()+1 == x_tiles())?1:0);
	}

	int tile_x(void) const
	noexcept {
		return tile_i()*(width()/x_tiles());
	}

	int y_tiles(void) const
	noexcept { return _y_tiles; }

	int tile_j(void) const
	noexcept {
		assert(_tile_j < _y_tiles);
		return _tile_j;
	}

	int tile_h(void) const
	noexcept {
		return (height()/y_tiles())+((tile_j()+1 == y_tiles())?1:0);
	}

	int tile_y(void) const
	noexcept {
		return tile_j()*(height()/y_tiles());
	}

	bool multiple_tiles(void) const
	noexcept {
		return x_tiles() > 1 || y_tiles() > 1;
	}


	bool pointer_dragging(int index = 0) const
	noexcept;

	example_state_variable_base<float>
	norm_pointer_x(int index = 0) const
	noexcept;

	example_state_variable_base<float>
	norm_pointer_y(int index = 0) const
	noexcept;

	example_state_variable_base<float>
	norm_pointer_z(int index = 0) const
	noexcept;
};

class example_state;

} // namespace oglplus

#endif
