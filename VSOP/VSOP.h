//
//  VSOP.h
//  VSOP
//
//  Created by Grayson Hansard on 9/11/15.
//  Copyright © 2015 From Concentrate Software. All rights reserved.
//

#pragma once

#include "Disposable.h"
#include "Observable.h"

#include <algorithm>
#include <functional>
#include <list>

namespace FCS
{
template <typename T>
class Property
{
public:
	Property()
		: _observables{}
		{};

	explicit Property(const T & value)
		: _value{value}, _observables{}
		{};
	
	Property(const Property &) = delete;
	Property(Property &&) = delete;
	
	Property & operator =(const Property &) = delete;
	Property & operator =(const T & value)
	{
		_value = value;
		for (auto & observer : _observables) observer(_value);
		return *this;
	}
	
	operator T() const { return _value; }
	Disposable operator <<(const std::function<void(const T &)> & action)
	{
		Observable<T> observable { action };
		_observables.push_back(observable);
		return Disposable {[&, observable](){
			auto it = std::find(_observables.begin(), _observables.end(), observable);
			if (it != _observables.end()) _observables.erase(it);
		}};
	}
	
private:
	T _value;
	std::list<Observable<T>> _observables;
};
}