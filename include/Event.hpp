#ifndef __EVENT_HPP__
#define __EVENT_HPP__

#include <chrono>

using namespace std::chrono_literals;

//-----------------------------------------------------------------------------
/**
 * Class Event
 * @brief : represents an event occurring in the system
 */
class Event {
  public:
    using date_of_event_t =
        std::chrono::time_point<std::chrono::system_clock>; /**< Alias to the
                                                               std::chrono::time_point<std::chrono::system_clock> type*/
    /**
     * Event criticity level
     */
    enum class level_t {
        INFO,    /**< Event criticity = INFO */
        WARNING, /**< Event criticity = WARNING */
        ERROR    /**< Event criticity = ERROR */
    };

  private:
    date_of_event_t _date{}; /**< Event's full date (date and time) */
    std::string _what{};     /**< Event's description  */
    level_t _level{};        /**< Event's criticity level */

    /**
     * @brief : creates a string version of the criticity level
     *
     * @param level_t level : criticity level
     *
     * @return std::string ("INFO", "WARNING" or "ERROR")
     */
    [[nodiscard]] std::string getStringLevel(level_t level) const noexcept;

  public:
    /**
     * @brief Ctors / Dtors rule of zero
     */
    Event() = default;                                  /**< Default constructor */
    Event(const Event &other) = default;                /**< Copy constructor */
    Event &operator=(const Event &other) = default;     /**< Copy assignment operator */
    Event(Event &&other) noexcept = default;            /**< Move constructor */
    Event &operator=(Event &&other) noexcept = default; /**< Move assignment operator */
    virtual ~Event() = default;                         /**< Destructor */
    /**
     * @brief "Standard" CTOR
     *
     * @param[in]   const date_of_event_t &date : Event's Date/time
     * @param[in]   const std::string &what : Event's description
     * @param[in]   level_t level : Event's criticity level
     */
    Event(const date_of_event_t &date, const std::string &what, level_t level)
        : _date{date}, _what{what}, _level{level} {};

    /**
     * @brief getters
     */
    [[nodiscard]] date_of_event_t getDate() const noexcept { return this->_date; };
    [[nodiscard]] std::string getWhat() const noexcept { return this->_what; };
    [[nodiscard]] level_t getLevel() const noexcept { return this->_level; };

    /**
     * @brief setters
     */
    void setDate(const date_of_event_t &date) noexcept { this->_date = date; };
    void setWhat(const std::string &what) noexcept { this->_what = what; };
    void setLevel(level_t level) noexcept { this->_level = level; };

    /**
     * @brief "converting" the event to a string
     *
     * @return  std::string : formatted string representing the event (date, message, level)
     */
    [[nodiscard]] std::string toString() const noexcept;
};
std::ostream &operator<<(std::ostream &os,
                         const Event &obj); /**< Overloaded output stream operator for Event objects */
#endif                                      /*  __EVENT_HPP__ */
