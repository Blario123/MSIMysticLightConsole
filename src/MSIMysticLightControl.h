//
// Created by Blair on 21/3/2021.
//

#ifndef MSIMYSTICLIGHTCONSOLE_MSIMYSTICLIGHTCONTROL_H
#define MSIMYSTICLIGHTCONSOLE_MSIMYSTICLIGHTCONTROL_H

#include "MysticLight/MysticLight_SDK.h"

class MSI {
public:
    static void getDevInfo(void);
    static int unloadDLL(void);
};
//TODO: Create global functions to control main.cpp from other applications, like log.cpp/.h

#endif //MSIMYSTICLIGHTCONSOLE_MSIMYSTICLIGHTCONTROL_H
