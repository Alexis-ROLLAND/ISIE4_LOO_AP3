#ifndef __DATALOGGER_HPP__
#define __DATALOGGER_HPP__

#include <exception>
#include <chrono>

using namespace     std::chrono_literals;

using date_of_event_t = std::chrono::time_point<std::chrono::system_clock>;

enum class Level_t {INFO, WARNING, ERROR};

struct  event_t{
    date_of_event_t     date{};
    std::string         what{};
    Level_t             Level{};

};


class   DataLogger{
    private:
        std::chrono::system_clock   internalClock{}; 
    protected:
        [[nodiscard]]   date_of_event_t getInternalClock() noexcept {return this->internalClock.now();};
    public:
        DataLogger() = default;
        virtual ~DataLogger() = default;

        virtual void    AddEvent(event_t &evt , bool setInternalTime = false) = 0;
        virtual void    dumpLog() = 0;
};

class   VectorDataLogger : public DataLogger{
    private:
        std::vector<event_t>    log{};
    
    public:
        VectorDataLogger() = default;
        virtual ~VectorDataLogger() = default;

        virtual void    AddEvent(event_t &evt, bool setInternalTime = false) override;     

};







#endif  /*  __DATALOGGER_HPP__  */