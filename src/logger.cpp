#include "logger.hpp"

#include <iostream>

static std::mutex _mutex;
static std::ofstream _logFile;

void Logger::log(LogLevel level, const std::string& message) {
        std::lock_guard<std::mutex> lock(_mutex);
        std::string prefix;
        switch (level) {
            case LogLevel::LOG_DEBUG:
                prefix = "[DEBUG] ";
                break;
            case LogLevel::LOG_INFO:
                prefix = "[INFO] ";
                break;
            case LogLevel::LOG_WARNING:
                prefix = "[WARNING] ";
                break;
            case LogLevel::LOG_ERROR:
                prefix = "[ERROR] ";
                break;
        }
        if (_logFile.is_open()) {
            _logFile << prefix << message << std::endl;
        }

    }

void Logger::debug(const std::string& message) {
    log(LogLevel::LOG_DEBUG, message);
}   
void Logger::info(const std::string& message) {
    log(LogLevel::LOG_INFO, message);
}
void Logger::warning(const std::string& message) {
    log(LogLevel::LOG_WARNING, message);
}
void Logger::error(const std::string& message) {
    log(LogLevel::LOG_ERROR, message);
}

void Logger::initialize() {
    std::lock_guard<std::mutex> lock(_mutex);
    _logFile.open("../log/application.log", std::ios::trunc);
    if(!_logFile.is_open()) {
        std::cout << "Failed to open log file" << std::endl;
    }
}