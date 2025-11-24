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

    /**
     * @brief Check if the event date is set or not based on expectation
     *
     * @param evt The event to check
     * @param shouldBeSet True if the event date should be set, false otherwise
     * @throws std::invalid_argument if the event date does not meet the expectation
     *
     */
    void ManageEventDate(Event &evt, bool setInternalTime) {
        if (!setInternalTime) {
            if (evt.getDate() == Event::date_of_event_t{}) throw std::invalid_argument{"Date of event not provided."};
        } else {
            if (evt.getDate() != Event::date_of_event_t{}) throw std::invalid_argument{"Date of event already set."};
            evt.setDate(this->getInternalClock());
        }
    }

  public:
    DataLogger() = default;                                       /**< Default constructor */
    DataLogger(const DataLogger &other) = default;                /**< Copy constructor */
    DataLogger &operator=(const DataLogger &other) = default;     /**< Copy assignment operator */
    DataLogger(DataLogger &&other) noexcept = default;            /**< Move constructor */
    DataLogger &operator=(DataLogger &&other) noexcept = default; /**< Move assignment operator */
    virtual ~DataLogger() = default;                              /**< Destructor */

    /**
     * @brief Add an event to the logger
     *
     * @param evt The event to add
     * @param setInternalTime If true, set the event's time to the internal clock's current time
     * @throws std::invalid_argument if event date is not set and setInternalTime is false
     * @throws std::invalid_argument if event date is already set and setInternalTime is true
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
    SortableDataLogger() = default;                                               /**< Default constructor */
    SortableDataLogger(const SortableDataLogger &other) = default;                /**< Copy constructor */
    SortableDataLogger &operator=(const SortableDataLogger &other) = default;     /**< Copy assignment operator */
    SortableDataLogger(SortableDataLogger &&other) noexcept = default;            /**< Move constructor */
    SortableDataLogger &operator=(SortableDataLogger &&other) noexcept = default; /**< Move assignment operator */
    virtual ~SortableDataLogger() = default;                                      /**< Destructor */

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