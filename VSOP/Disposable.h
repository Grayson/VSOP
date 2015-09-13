//
//  Disposable.h
//  VSOP
//
//  Created by Grayson Hansard on 9/11/15.
//  Copyright © 2015 From Concentrate Software. All rights reserved.
//

#pragma once

#include <functional>

namespace FCS
{
class Disposable
{
public:
	Disposable(const std::function<void()> & action) : _action{action}, _identifier{&_identifier} {};
	~Disposable() { _action(); };
	
	Disposable(const Disposable & other) = delete;
	Disposable & operator= (const Disposable & other) = delete;
	
	Disposable(Disposable && other) = default;
	Disposable & operator= (Disposable && other) = default;
	
private:
	std::function<void()> _action;
	void * _identifier;
};
}