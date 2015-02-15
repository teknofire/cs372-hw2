//
//  scorer.h
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __bowling_kata__scorer__
#define __bowling_kata__scorer__

#include <vector>

class Scorer
{
private:
    std::vector<int> _throws;
    
    int _currentThrow;
    
    bool strike();
    bool spare();
    
    int nextTwoBalls();
    int nextBall();
    int twoBallsInFrame();
    
public:
    Scorer() = default;
    ~Scorer() = default;
    
    int score();
    void add(int);
    int scoreForFrame(int);
};

#endif /* defined(__bowling_kata__scorer__) */
