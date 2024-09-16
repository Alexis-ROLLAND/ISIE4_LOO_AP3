#include <print>

#include "DataLogger.hpp"


int main(void){

    event_t myEvent{};

    myEvent.Level = Level_t::WARNING;
    myEvent.what = "Warning event";
        
    VectorDataLogger    myVectorDataLogger{};

    try{
        myVectorDataLogger.AddEvent(myEvent);
    }
    catch(const std::invalid_argument &e){
        std::println("Exception catched ({}) OK.",e.what());
    }

    myEvent.date = std::chrono::system_clock{}.now();

    try{
        myVectorDataLogger.AddEvent(myEvent);
    }
    catch(const std::invalid_argument &e){
        std::println("Exception catched ({}) NOT OK.",e.what());
    }

}


