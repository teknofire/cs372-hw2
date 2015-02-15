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
    return scoreForFrame(_currentFrame -1);
}

void Game::add(int pins)
{
    _throws.push_back(pins);
    adjustCurrentFrame(pins);
}

void Game::adjustCurrentFrame(int pins)
{
    if (_firstFrameThrow)
    {
        if (pins == 10)
            _currentFrame++;
        else
            _firstFrameThrow = false;
    }
    else
    {
        _firstFrameThrow = true;
        _currentFrame++;
    }
    _currentFrame = std::min(11, _currentFrame);
}

int Game::scoreForFrame(int frame)
{
    int score = 0;
    _currentThrow = 0;
    
    for(int currentFrame = 0; currentFrame < frame; currentFrame++)
    {
        
        if (strike())
            score += 10 + nextTwoBalls();
        else if (spare())
            score += 10 + nextBall();
        else
            score += twoBallsInFrame();
    }
    
    return score;
}

bool Game::strike()
{
    if ( nextBall() == 10 )
    {
        _currentThrow++;
        return true;
    }
    
    return false;
}

bool Game::spare()
{
    if ( nextTwoBalls() == 10 )
    {
        _currentThrow += 2;
        return true;
    }
    
    return false;
}

int Game::nextBall()
{
    return _throws[_currentThrow];
}

int Game::nextTwoBalls()
{
    return _throws[_currentThrow] + _throws[_currentThrow+1];
}

int Game::twoBallsInFrame()
{
    return _throws[_currentThrow++] + _throws[_currentThrow++];
}

int Game::getCurrentFrame()
{
    return _currentFrame;
}