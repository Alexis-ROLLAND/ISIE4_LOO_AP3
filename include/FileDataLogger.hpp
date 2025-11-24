#ifndef __FILEDATALOGGER_HPP__
#define __FILEDATALOGGER_HPP__

#include "DataLogger.hpp"
#include <exception>
#include <filesystem>
#include <fstream>
#include <ranges>

/**
 * Class FileDataLogger
 *
 * If the log file doesn't exist, it's created, otherwise Events are appended to the file.
 */
class FileDataLogger : public DataLogger {
  private:
    const std::filesystem::path logFilePath{};                                        /**< Path to the log file */
    std::filesystem::path getFilePath() const noexcept { return this->logFilePath; }; /**< Get the log file path */
  public:
    FileDataLogger() = delete;
    explicit FileDataLogger(const std::string &FileName) : logFilePath{FileName} {};
    virtual ~FileDataLogger() = default;

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
    [[nodiscard]] virtual std::size_t getNbEvents() override;
};

#endif /*  __FILEDATALOGGER_HPP__  */
