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
    
    SECTION( "should score perfect game" )
    {
        for (int i=0; i<12; i++)
        {
            g.add(10);
        }
        REQUIRE( g.score() == 300 );
        REQUIRE( g.getCurrentFrame() == 11 );
    }
    
    SECTION( "should score if last throw is a stike" )
    {
        for (int i=0; i<9; i++)
        {
            g.add(0);
            g.add(0);
        }
        g.add(2);
        g.add(8); // 10th frame spare
        g.add(10); // Strike in last position of array.
        REQUIRE( g.score() == 20 );
    }
    
    SECTION( "should score given game" )
    {
        g.add(1);
        g.add(4);
        g.add(4);
        g.add(5);
        g.add(6);
        g.add(4);
        g.add(5);
        g.add(5);
        g.add(10);
        g.add(0);
        g.add(1);
        g.add(7);
        g.add(3);
        g.add(6);
        g.add(4);
        g.add(10);
        g.add(2);
        g.add(8);
        g.add(6);
        REQUIRE( g.score() == 133 );
    }
    
    SECTION( "should test heartbreak game" )
    {
        for (int i=0; i<11; i++)
            g.add(10);
        g.add(9);
        REQUIRE( g.score() == 299 );
    }
    
    SECTION( "should score 10 frame spare game" )
    {
        for (int i=0; i<9; i++)
            g.add(10);
        g.add(9);
        g.add(1);
        g.add(1);
        REQUIRE( g.score() == 270 );
    }
}