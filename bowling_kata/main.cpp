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
#include "frame.h"
#include "game.h"

TEST_CASE( "bowling kata frames") {
    Frame f;
    
    REQUIRE( f.getScore() == 0 );
    
    SECTION( "add throw to frame" )
    {
        f.add(5);
        REQUIRE( f.getScore() == 5 );
    }
}

TEST_CASE( "bowling kata games" ) {
    Game g;
    
    REQUIRE( g.score() == 0 );
}