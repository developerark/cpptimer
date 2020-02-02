//
//  cpptimer.hpp
//  cpptimer
//
//  Created by Aswin Raj Kharel on 2/2/20.
//  Copyright © 2020 Aswin Raj Kharel. All rights reserved.
//

#ifndef cpptimer_hpp
#define cpptimer_hpp

#include <stdio.h>
#include <iostream>
#include <atomic>

class cpptimer{
private:
    std::function<void()> _callback;
    std::atomic<bool> _isValid;
    std::chrono::milliseconds _duration;
    void _start();
public:
    cpptimer(std::function<void()>, std::chrono::milliseconds);
    void invalidate();
    ~cpptimer();
    void start();
};

#endif /* cpptimer_hpp */
