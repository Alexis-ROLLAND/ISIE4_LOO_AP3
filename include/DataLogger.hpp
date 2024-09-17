#ifndef __DATALOGGER_HPP__
#define __DATALOGGER_HPP__

#include "Event.hpp"

#include <exception>
#include <chrono>

using namespace     std::chrono_literals;


//-----------------------------------------------------------------------------

class   DataLogger{
    private:
        std::chrono::system_clock   internalClock{}; 
    protected:
        [[nodiscard]]   Event::date_of_event_t getInternalClock() noexcept {return this->internalClock.now();};
    public:
        DataLogger() = default;
        virtual ~DataLogger() = default;

        virtual void    AddEvent(Event &evt , bool setInternalTime = false) = 0;
        virtual void    dumpLog() = 0;
};
//-----------------------------------------------------------------------------
class   VectorDataLogger : public DataLogger{
    private:
        std::vector<Event>    log{};
    
    public:
        VectorDataLogger() = default;
        virtual ~VectorDataLogger() = default;

        virtual void    AddEvent(Event &evt, bool setInternalTime = false) override;     
        virtual void    dumpLog() override {};
};







#endif  /*  __DATALOGGER_HPP__  */