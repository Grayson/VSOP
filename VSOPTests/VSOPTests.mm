//
//  VSOPTests.m
//  VSOPTests
//
//  Created by Grayson Hansard on 9/11/15.
//  Copyright © 2015 From Concentrate Software. All rights reserved.
//

#import <XCTest/XCTest.h>
#include "VSOP.h"

@interface VSOPTests : XCTestCase

@end

@implementation VSOPTests

- (void)testExample
{
	
	FCS::Property<int> p { 42 };
	
	bool didObserve = false;
	auto disposable = p << [&](int _) { didObserve = true; };
	
	bool didDispose = true;
	p << [&](int _) { didDispose = false; }; /* auto-disposed */
	
	p = 43;
	
	XCTAssert(43 == p);
	XCTAssert(true == didObserve);
	XCTAssert(true == didDispose);
}

@end
