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
        {
            _currentThrow++;
            score += 10 + _throws[_currentThrow] + _throws[_currentThrow + 1];
        }
        else
        {
            score += handleSecondThrow();
        }
    }
    
    return score;
}

bool Game::strike()
{
    return _throws[_currentThrow] == 10;
}

int Game::handleSecondThrow()
{
    auto score = _throws[_currentThrow] + _throws[_currentThrow+1];
    
    if (score == 10)
        score += _throws[_currentThrow+2];
    
    _currentThrow += 2;
    return score;
}

int Game::getCurrentFrame()
{
    return _currentFrame;
}