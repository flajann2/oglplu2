/**
 *  @file eagine/outcome.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_OUTCOME_1509260923_HPP
#define EAGINE_OUTCOME_1509260923_HPP

#include "deferred_handler.hpp"
#include <cassert>

namespace eagine {

template <typename T>
class basic_outcome_storage;

template <typename T>
class basic_outcome_storage
{
private:
	T _val;
public:
	basic_outcome_storage(void) = default;

	constexpr
	basic_outcome_storage(T val)
	noexcept
	 : _val(val)
	{ }

	constexpr
	T get(void) const
	noexcept
	{
		return _val;
	}
};

template <typename T>
class basic_outcome_storage<T&>
{
private:
	T* _ref;
public:
	constexpr
	basic_outcome_storage(void)
	noexcept
	 : _ref(nullptr)
	{ }

	basic_outcome_storage(T& ref)
	noexcept
	 : _ref(&ref)
	{ }

	T& get(void) const
	noexcept
	{
		assert(_ref != nullptr);
		return *_ref;
	}
};

template <typename T, typename ErrorData>
class basic_outcome
{
private:
	deferred_handler<ErrorData> _handler;
	basic_outcome_storage<T> _value;
public:
	basic_outcome(deferred_handler<ErrorData>&& handler)
	noexcept
	 : _handler(std::move(handler))
	{ }

	basic_outcome(T value)
	noexcept
	 : _value(value)
	{ }

	T get(void)
	{
		_handler.trigger();
		return _value.get();
	}

	operator T (void)
	{
		return get();
	}

	basic_outcome& ignore_error(void)
	noexcept
	{
		_handler.cancel();
		return *this;
	}

	bool done(void) const
	noexcept
	{
		return !_handler;
	}

	bool done_without_error(void)
	noexcept
	{
		return !_handler.cancel();
	}
};

template <typename ErrorData>
class basic_outcome<void, ErrorData>
{
private:
	deferred_handler<ErrorData> _handler;
public:
	basic_outcome(void) = default;

	basic_outcome(deferred_handler<ErrorData>&& handler)
	noexcept
	 : _handler(std::move(handler))
	{ }

	basic_outcome& ignore_error(void)
	noexcept
	{
		_handler.cancel();
		return *this;
	}

	bool done(void) const
	noexcept
	{
		return !_handler;
	}

	bool done_without_error(void)
	noexcept
	{
		return !_handler.cancel();
	}
};

} // namespace eagine

#endif // include guard