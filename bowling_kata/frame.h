//
//  frame.h
//  bowling_kata
//
//  Created by Will Fisher on 2/14/15.
//  Copyright (c) 2015 Will Fisher. All rights reserved.
//

#ifndef __bowling_kata__frame__
#define __bowling_kata__frame__

class Frame
{
    
private:
    int _score;
    
public:
    Frame(): _score(0)
    { }
    
    int getScore();
    void add(int);
};

#endif /* defined(__bowling_kata__frame__) */
