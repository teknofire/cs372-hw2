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
    int score = 0;
    
    for(auto i:_throws)
        score += i;
    
    return score;
}

void Game::add(int pins)
{
    _throws.push_back(pins);
    
    if (_firstFrameThrow)
    {
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
        auto secondThrow = _throws[currentThrow++];
        auto frameScore = firstThrow + secondThrow;
        
        if (frameScore == 10)
            frameScore += _throws[currentThrow];
        
        score += frameScore;
    }
    
    return score;
}

int Game::getCurrentFrame()
{
    return _currentFrame;
}