#pragma once

#include <string>

class Application {
public:
    Application();
    ~Application();

    // lifehooks
    int initialize();
    void shutdown();

    void run();

private:
    std::string _version = "0.0.1";
    bool _running = false;
};