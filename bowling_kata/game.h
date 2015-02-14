//
//  game.h
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __bowling_kata__game__
#define __bowling_kata__game__

#include <vector>

class Game
{
private:
    std::vector<int> _throws;
    int _currentFrame;
    bool _firstFrameThrow;
    
public:
    Game(): _currentFrame(1), _firstFrameThrow(true) {}
    
    int score();
    void add(int);
    int scoreForFrame(int);
    int getCurrentFrame();
};

#endif /* defined(__bowling_kata__game__) */
