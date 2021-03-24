//
// Created by Blair on 19/3/2021.
//
#include <string>

#ifndef MSIMYSTICLIGHTCONSOLE_TERMINAL_H
#define MSIMYSTICLIGHTCONSOLE_TERMINAL_H

class Terminal {
public:
    Terminal(int width) {
        getTerminalWidth();
    };
    void terminalMain(void);
    void setTerminalWidth(int width);
    void showOptions(int length, std::string title, std::string options[]);
    void showOptions(int length, std::string title);
    int getTerminalWidth(void);
private:
    int cons_width;
protected:
};

#endif //MSIMYSTICLIGHTCONSOLE_TERMINAL_H
