//
//  game.h
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __bowling_kata__game__
#define __bowling_kata__game__

#include "scorer.h"
#include <memory>

class Game
{
private:
    int _currentFrame;
    bool _firstFrameThrow;

    void adjustCurrentFrame(int);
    void advanceFrame();
    
    std::unique_ptr<Scorer> _scorer;
    
public:
    Game(): _currentFrame(0), _firstFrameThrow(true), _scorer(std::make_unique<Scorer>()) {}
    ~Game() = default;
    
    int score();
    void add(int);
    int scoreForFrame(int);
    
};

#endif /* defined(__bowling_kata__game__) */
