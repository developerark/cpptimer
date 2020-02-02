//
//  cpptimer.cpp
//  cpptimer
//
//  Created by Aswin Raj Kharel on 2/2/20.
//  Copyright © 2020 Aswin Raj Kharel. All rights reserved.
//

#include "cpptimer.hpp"
#include <thread>

cpptimer::cpptimer(std::function<void()> callback, std::chrono::milliseconds duration):
    _callback(callback),
    _isValid(false),
    _duration(duration){}

void cpptimer::start(){
    this->_isValid = true;
    std::thread(&cpptimer::_start, this).detach();
}

void cpptimer::_start(){
    while(this->_isValid){
        this->_callback();
        std::this_thread::sleep_for(this->_duration);
    }
}

void cpptimer::invalidate(){
    this->_isValid = false;
}

cpptimer::~cpptimer(){
    
}
