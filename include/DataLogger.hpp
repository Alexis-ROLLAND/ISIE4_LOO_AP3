#ifndef __DATALOGGER_HPP__
#define __DATALOGGER_HPP__

#include "Event.hpp"

#include <algorithm>
#include <chrono>
#include <exception>
#include <print>

using namespace std::chrono_literals;

//-----------------------------------------------------------------------------
/**
 * Class DataLogger
 *
 * Non Sortable generic data logger
 */
class DataLogger {
  private:
    std::chrono::system_clock internalClock{}; /**< Internal clock to timestamp events */

  protected:
    /**
     * @brief Get the Internal Clock object
     *
     * @return Event::date_of_event_t : current time point from internal clock
     */
    [[nodiscard]] Event::date_of_event_t getInternalClock() noexcept { return this->internalClock.now(); };

  public:
    DataLogger() = default;
    virtual ~DataLogger() = default;

    /**
     * @brief Add an event to the logger
     *
     * @param evt The event to add
     * @param setInternalTime If true, set the event's time to the internal clock's current time
     */
    virtual void AddEvent(Event &evt, bool setInternalTime = false) = 0;

    /**
     * @brief Dump the log contents
     *
     */
    virtual void dumpLog() = 0;

    /**
     * @brief Get the Number of Events object
     * @return std::size_t : number of events in the log
     */
    virtual std::size_t getNbEvents() = 0;
};
//-----------------------------------------------------------------------------
/**
 * Class SortableDataLogger
 *
 * Sortable generic data logger - Data structure MUST be sortable
 * (ie Vector...)
 */
class SortableDataLogger : public DataLogger {
  private:
  protected:
  public:
    SortableDataLogger() = default;
    virtual ~SortableDataLogger() = default;

    /**
     * @brief Sort the log by date
     *
     * @param ascending If true, sort in ascending order; otherwise, descending
     */
    virtual void sortByDate(bool ascending = true) = 0;

    /**
     * @brief Sort the log by criticity
     *
     * @param ascending If true, sort in ascending order; otherwise, descending
     */
    virtual void sortByCriticity(bool ascending = true) = 0;

    /**
     * @brief Sort the log by what
     *
     * @param ascending If true, sort in ascending order; otherwise, descending
     */
    virtual void sortByWhat(bool ascending = true) = 0;
};
//-----------------------------------------------------------------------------

#endif /*  __DATALOGGER_HPP__  */