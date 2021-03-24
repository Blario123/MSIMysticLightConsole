//
// Created by Blair on 21/3/2021.
//

#ifndef MSIMYSTICLIGHTCONSOLE_LOG_H
#define MSIMYSTICLIGHTCONSOLE_LOG_H

#include "terminal.h"
#include "MSIMysticLightControl.h"

class Log {
public:
    /*
    When using BSTR, message is sent using wstring for debug codes
    This needs an overloaded function for all the functions.
    */
    static void warning(const std::string& wwmessage);
    static void warning(const std::wstring& wsmessage);
    static void error(const std::string& esmessage);
    static void error(const std::wstring& ewmessage);
    static void info(const std::string& smessage);
    static void info(const std::wstring& wmessage);
    static void debug(const std::string &dsmessage);
    static void debug(const std::wstring &dwmessage);
    static void init();
private:
};

#endif //MSIMYSTICLIGHTCONSOLE_LOG_H
