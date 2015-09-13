//
//  Observable.h
//  VSOP
//
//  Created by Grayson Hansard on 9/12/15.
//  Copyright © 2015 From Concentrate Software. All rights reserved.
//

#pragma once

#include <atomic>

namespace FCS
{
template <typename T>
class Observable
{
public:
	explicit Observable(std::function<void(const T &)> action)
		: _action{action}
		, _identifier{0}
	{
		static std::atomic<size_t> s_counter;
		_identifier = s_counter.fetch_add(1);
	};
	
	Observable(const Observable & other)
		: _action{other._action}
		, _identifier{other._identifier}
		{};
	
	Observable(Observable && other)
	{
		std::swap(_action, other._action);
		std::swap(_identifier, other._identifier);
	}
	
	Observable & operator= (const Observable & other)
	{
		if (&other == this)
			return *this;
		_action = other._action;
		_identifier = other._identifier;
		return *this;
	}
	
	bool operator == (const Observable & other) { return _identifier == other._identifier; };
	void operator()(const T & value) { _action(value); };
	
private:
	std::function<void(const T &)> _action;
	size_t _identifier;
};
}