# cpptimer
This module allows you to schedule recurring tasks in C++

## Basic Examples
```cpp
	
#include <iostream>
#include "cpptimer.hpp"
#include <vector>

class Item {
public:
    static void classFunction(std::string arg){
        std::cout << "I am a " << arg << std::endl;
    }
    void memberFunction(std::string arg){
        std::cout << "I am a " << arg << std::endl;
    }
};

void fileFunction(std::string arg){
    std::cout << "I am a " << arg << std::endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Item a;
    cpptimer timer1(std::bind(&Item::classFunction, "classFunction"), std::chrono::milliseconds(1000));
    cpptimer timer2(std::bind(&Item::memberFunction, a, "memberFunction"), std::chrono::milliseconds(1000));
    cpptimer timer3(std::bind(fileFunction, "memberFunction"), std::chrono::milliseconds(1000));
    timer1.start();
    timer2.start();
    timer3.start();
    
    std::getchar();
    timer1.invalidate();
    timer2.invalidate();
    timer3.invalidate();
    std::getchar();
    return 0;
}
```
