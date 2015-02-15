//
//  game.cpp
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "game.h"
#include <algorithm>  // std::min

int Game::score()
{
    return scoreForFrame(_currentFrame);
}

int Game::scoreForFrame(int frame)
{
    return _scorer->scoreForFrame(frame);
}

void Game::add(int pins)
{
    _scorer->add(pins);
    adjustCurrentFrame(pins);
}

void Game::adjustCurrentFrame(int pins)
{
    if (_firstFrameThrow)
        _firstFrameThrow = adjustFrameForStrike(pins);
    else
    {
        _firstFrameThrow = true;
        advanceFrame();
    }
}

bool Game::adjustFrameForStrike(int pins)
{
    if (pins == 10)
    {
        advanceFrame();
        return true;
    }
    
    return false;
}

void Game::advanceFrame()
{
    _currentFrame = std::min(10, _currentFrame + 1);
}