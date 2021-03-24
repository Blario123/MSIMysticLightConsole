//
// Created by Blair on 19/3/2021.
//

#include <windows.h>
#include <iostream>
#include <cmath>
#include "terminal.h"

CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;

using namespace std;

int Terminal::getTerminalWidth() {
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleScreenBufferInfo);
    cons_width = consoleScreenBufferInfo.dwSize.X;
    return cons_width;
}

void Terminal::setTerminalWidth(int width) {
    cons_width = width;
}

void Terminal::showOptions(int length, string title) {
    int titleLength = title.length();
    for(int i = 1; i <= ceil((float)titleLength/(float)cons_width); i++) {

    }
}

void Terminal::showOptions(int length, string title, string options[]) {
    int titleLength = title.length();
    cout << ceil(titleLength/cons_width);
//    cout << titleLength << endl;
}

void Terminal::terminalMain(void){

}
