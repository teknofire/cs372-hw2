//
//  frame.cpp
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#include "frame.h"

int Frame::getScore()
{
    return _score;
}

void Frame::add(int pins)
{
    _score += pins;
}