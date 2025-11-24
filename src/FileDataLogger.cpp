#include "FileDataLogger.hpp"

//-----------------------------------------------------------------------------
void FileDataLogger::AddEvent(Event &evt, bool setInternalTime) {

    this->ManageEventDate(evt, setInternalTime);

    std::ofstream logstream(this->getFilePath(),
                            std::ios::app); /** Open in append mode - No need to close : RAII object */
    logstream << evt.toString() << std::endl;
}
//-----------------------------------------------------------------------------
void FileDataLogger::dumpLog() {
    std::ifstream logstream(this->getFilePath());
    std::string line{};

    while (std::getline(logstream, line))
        std::println("{}", line);
}
//-----------------------------------------------------------------------------
std::size_t FileDataLogger::getNbEvents() {
    std::ifstream logstream(this->getFilePath());
    std::string line{};

    unsigned int nbLines{0};   // Initializing a variable to count lines

    while (std::getline(logstream, line))
        nbLines++;

    return static_cast<std::size_t>(nbLines);
}
//-----------------------------------------------------------------------------
