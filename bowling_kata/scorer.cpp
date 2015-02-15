//
//  scorer.cpp
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "scorer.h"

void Scorer::add(int pins)
{
    _throws.push_back(pins);
}
int Scorer::scoreForFrame(int frame)
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

bool Scorer::strike()
{
    if ( nextBall() == 10 )
    {
        _currentThrow++;
        return true;
    }
    
    return false;
}

bool Scorer::spare()
{
    if ( nextTwoBalls() == 10 )
    {
        _currentThrow += 2;
        return true;
    }
    
    return false;
}

int Scorer::nextBall()
{
    return _throws[_currentThrow];
}

int Scorer::nextTwoBalls()
{
    return _throws[_currentThrow] + _throws[_currentThrow+1];
}

int Scorer::twoBallsInFrame()
{
    return _throws[_currentThrow++] + _throws[_currentThrow++];
}