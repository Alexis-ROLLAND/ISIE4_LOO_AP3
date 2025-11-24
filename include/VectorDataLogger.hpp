#ifndef __VECTOR_DATA_LOGGER_HPP__
#define __VECTOR_DATA_LOGGER_HPP__

#include "DataLogger.hpp"
#include <print>

//-----------------------------------------------------------------------------
class VectorDataLogger : public SortableDataLogger {
  private:
    std::vector<Event> log{}; /**< Vector to store events */

  public:
    VectorDataLogger() = default;                                             /**< Default constructor */
    VectorDataLogger(const VectorDataLogger &other) = default;                /**< Copy constructor */
    VectorDataLogger &operator=(const VectorDataLogger &other) = default;     /**< Copy assignment operator */
    VectorDataLogger(VectorDataLogger &&other) noexcept = default;            /**< Move constructor */
    VectorDataLogger &operator=(VectorDataLogger &&other) noexcept = default; /**< Move assignment operator */
    virtual ~VectorDataLogger() = default;                                    /**< Destructor */

    /**
     * @brief Add an event to the logger
     *
     * @param evt The event to add
     * @param setInternalTime If true, set the event's time to the internal clock's current time
     */
    virtual void AddEvent(Event &evt, bool setInternalTime = false) override;

    /**
     * @brief Dump the log contents
     *
     */
    virtual void dumpLog() override;

    /**
     * @brief Get the Number of Events object
     * @return std::size_t : number of events in the log
     */
    [[nodiscard]] virtual std::size_t getNbEvents() override { return this->log.size(); };

    /**
     * @brief Sort the log by date
     *
     * @param ascending If true, sort in ascending order; otherwise, descending
     */
    virtual void sortByDate(bool ascending = true) override;

    /**
     * @brief Sort the log by criticity
     *
     * @param ascending If true, sort in ascending order; otherwise, descending
     */
    virtual void sortByCriticity(bool ascending = true) override;

    /**
     * @brief Sort the log by what
     *
     * @param ascending If true, sort in ascending order; otherwise, descending
     */
    virtual void sortByWhat(bool ascending = true) override;
};

#endif
