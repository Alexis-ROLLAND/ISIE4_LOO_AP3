#include <print>

#include "DataLogger.hpp"


int main(void){

    
    Event   myEvent{};

    myEvent.setLevel(Event::level_t::WARNING);
    myEvent.setWhat("Warning event");
        
    VectorDataLogger    myVectorDataLogger{};

    try{
        myVectorDataLogger.AddEvent(myEvent);
    }
    catch(const std::invalid_argument &e){
        std::println("Exception catched ({}) OK.",e.what());
    }

    myEvent.setDate(std::chrono::system_clock{}.now());

    try{
        myVectorDataLogger.AddEvent(myEvent);
    }
    catch(const std::invalid_argument &e){
        std::println("Exception catched ({}) NOT OK.",e.what());
    }

    std::println("toString = {:s}",myEvent.toString());

    
}


