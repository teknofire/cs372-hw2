//
//  main.cpp
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>

class Frame
{
public:
    int getScore()
    {
        return 0;
    }
};

TEST_CASE( "bowling kata") {
    Frame f;
    
    REQUIRE( f.getScore() == 0 );
    
    SECTION( "add throw to frame" )
    {
        f.add(5)
        REQUIRE( f.getScore() == 5 );
    }
}