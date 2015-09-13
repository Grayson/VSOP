# VSOP

Very Simple Observer Properties (or Pattern) is a handful of simple C++ header files that enable a basic callback when data changes.

## Sample code

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

## Contact information

* Email: [Grayson Hansard](grayson.hansard@gmail.com)
* Twitter: [@Grayson](http://twitter.com/Grayson)
