#ifndef __EVENT_HPP__
#define __EVENT_HPP__


#include <chrono>

using namespace     std::chrono_literals;

//-----------------------------------------------------------------------------
class   Event{
    public:
        using date_of_event_t = std::chrono::time_point<std::chrono::system_clock>;
        enum class level_t {INFO, WARNING, ERROR};
    private:
        date_of_event_t     date{};
        std::string         what{};
        level_t             level{};

        [[nodiscard]] std::string getStringLevel(level_t level) const noexcept;

    public:
        Event() = default;
        Event(const date_of_event_t &date,const std::string &what, level_t level):date{date},what{what},level{level}{};
        virtual ~Event() = default;

        [[nodiscard]]   date_of_event_t getDate() const noexcept {return this->date;};
        [[nodiscard]]   std::string getWhat() const noexcept {return this->what;};
        [[nodiscard]]   level_t     getLevel() const noexcept {return this->level;};

        void    setDate(const date_of_event_t &date) noexcept {this->date = date;};
        void    setWhat(const std::string &what) noexcept {this->what = what;};
        void    setLevel(level_t level) noexcept {this->level = level;};

        [[nodiscard]]   std::string toString() const noexcept;

};

#endif      /*  __EVENT_HPP__ */