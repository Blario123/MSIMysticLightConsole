//
// Created by Blair on 21/3/2021.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "log.h"
#include "terminal.h"

int t_width;

std::string convertWstringToString(std::wstring &from) {
    std::string to(from.begin(), from.end());
    return to;
}

void Log::init() {
    Terminal logTerminal(0);
    t_width = logTerminal.getTerminalWidth();
}

void Log::info(const std::string& ismessage) {
    std::ostringstream infoMessage;
    infoMessage << std::setfill(' ')
                << "[Info]\t" << ismessage
                << std::setw(t_width)
                << std::endl;
    std::cout << infoMessage.str();
}

void Log::info(const std::wstring& iwmessage) {
    std::ostringstream infoMessage;
    infoMessage << std::setfill(' ')
                << "[Info]\t" << convertWstringToString((std::wstring &) iwmessage)
                << std::setw(t_width)
                << std::endl;
    std::cout << infoMessage.str();
}

void Log::debug(const std::string& dsmessage) {
    std::ostringstream debugMessage;
    debugMessage << std::setfill(' ')
                << "[Debug]\t" << dsmessage
                << std::setw(t_width)
                << std::endl;
    std::cout << debugMessage.str();
}

void Log::debug(const std::wstring& dwmessage) {
    std::ostringstream debugMessage;
    debugMessage << std::setfill(' ')
                 << "[Debug]\t" << convertWstringToString((std::wstring &) dwmessage)
                 << std::setw(t_width)
                 << std::endl;
    std::cout << debugMessage.str();
}

void Log::error(const std::string& esmessage) {
    std::ostringstream errorMessage;
    errorMessage << std::setfill(' ')
                << "[Error]\t" << esmessage
                << std::setw(t_width)
                << std::endl;
    std::cout << errorMessage.str();
}

void Log::error(const std::wstring& ewmessage) {
    std::ostringstream errorMessage;
    errorMessage << std::setfill(' ')
                 << "[Error]\t" << convertWstringToString((std::wstring &) ewmessage)
                 << std::setw(t_width)
                 << std::endl;
    std::cout << errorMessage.str();
}

void Log::warning(const std::string& wsmessage) {
    std::ostringstream warningMessage;
    warningMessage << std::setfill(' ')
                << "[Warn]\t" << wsmessage
                << std::setw(t_width)
                << std::endl;
    std::cout << warningMessage.str();
}

void Log::warning(const std::wstring& wwmessage) {
    std::ostringstream warningMessage;
    warningMessage << std::setfill(' ')
                   << "[Warn]\t" << convertWstringToString((std::wstring &) wwmessage)
                   << std::setw(t_width)
                   << std::endl;
    std::cout << warningMessage.str();
}
