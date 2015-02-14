//
//  game.h
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __bowling_kata__game__
#define __bowling_kata__game__

class Game
{
private:
    int _score;
    
public:
    Game(): _score(0)
    {}
    
    int score();
    void add(int);
};

#endif /* defined(__bowling_kata__game__) */
