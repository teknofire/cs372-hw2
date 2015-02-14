//
//  game.cpp
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "game.h"

int Game::score()
{
    return _score;
}

void Game::add(int pins)
{
    _score += pins;
}