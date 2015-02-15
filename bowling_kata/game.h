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
    int _currentThrow;
    int _firstThrow;
    int _secondThrow;
    
public:
    Game(): _currentFrame(1), _firstFrameThrow(true) {}
    ~Game() = default;
    
    int score();
    void add(int);
    int scoreForFrame(int);
    int getCurrentFrame();
    void adjustCurrentFrame(int);
    
    int handleSecondThrow();
    
};

#endif /* defined(__bowling_kata__game__) */
