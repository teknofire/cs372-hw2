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
    
    SECTION( "should add multiple throws to game" )
    {
        g.add(5);
        g.add(4);
        
        REQUIRE( g.score() == 9 );
        REQUIRE( g.getCurrentFrame() == 2 );
    }
    
    SECTION( "should add multiple throws across frames" )
    {
        g.add(5);
        g.add(4);
        g.add(7);
        g.add(2);
        
        REQUIRE( g.score() == 18 );
        REQUIRE( g.scoreForFrame(1) == 9 );
        REQUIRE( g.scoreForFrame(2) == 18 );
        REQUIRE( g.getCurrentFrame() == 3 );
    }
    
    SECTION( "should score simple spare case" )
    {
        g.add(3);
        g.add(7);
        g.add(3);
        
        REQUIRE( g.scoreForFrame(1) == 13 );
        REQUIRE( g.score() == 13 );
        REQUIRE( g.getCurrentFrame() == 2 );
        
    }
    
    SECTION( "should score simple frame after spare frame" )
    {
        g.add(3);
        g.add(7);
        g.add(3);
        g.add(2);
        
        REQUIRE( g.scoreForFrame(1) == 13 );
        REQUIRE( g.scoreForFrame(2) == 18 );
        REQUIRE( g.score() == 18 );
        REQUIRE( g.getCurrentFrame() == 3 );
    }
    
    SECTION( "should score multiple spares case" )
    {
        g.add(3);
        g.add(7);
        g.add(6);
        g.add(4);
        g.add(3);
        
        REQUIRE( g.scoreForFrame(1) == 16 );
        REQUIRE( g.scoreForFrame(2) == 29 );
        REQUIRE( g.score() == 29 );
        REQUIRE( g.getCurrentFrame() == 3 );
    }
    
    SECTION( "should score simple strike case" )
    {
        g.add(10);
        g.add(3);
        g.add(6);
        
        REQUIRE( g.scoreForFrame(1) == 19 );
        REQUIRE( g.score() == 28 );
        REQUIRE( g.getCurrentFrame() == 3 );
    }
}