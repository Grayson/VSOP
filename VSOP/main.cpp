//
//  main.cpp
//  VSOP
//
//  Created by Grayson Hansard on 9/11/15.
//  Copyright © 2015 From Concentrate Software. All rights reserved.
//

#include <iostream>
#include "VSOP.h"

class Foo
{
public:
	FCS::Property<int> bar;
};

int main(int argc, const char * argv[])
{
	Foo foo {};
	{
		auto observer = foo.bar << [](int change) { std::cout << "Foo.bar changed to " << change << std::endl; };
		foo.bar = 1;
	}
	foo.bar = 2;
	return 0;
}
