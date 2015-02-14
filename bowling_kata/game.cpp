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
}

int Game::scoreForFrame(int frame)
{
    int score = 0;
    int currentThrow = 0;
    
    for(int currentFrame = 0; currentFrame < frame; currentFrame++)
    {
        
        auto firstThrow = _throws[currentThrow++];
        
        if (firstThrow == 10)
            score += 10 + _throws[currentThrow] + _throws[currentThrow + 1];
        else
        {
            auto secondThrow = _throws[currentThrow++];
            auto frameScore = firstThrow + secondThrow;
            
            if (frameScore == 10)
                frameScore += _throws[currentThrow];
            
            score += frameScore;
        }
    }
    
    return score;
}

int Game::getCurrentFrame()
{
    return _currentFrame;
}