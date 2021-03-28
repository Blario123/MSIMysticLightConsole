//
// Created by Blair on 19/3/2021.
//

#include <windows.h>
#include <iostream>
#include <atlsafe.h>
#include <winbase.h>
#include <sstream>
#include <assert.h>

#include "MysticLight/MysticLight_SDK.h"
#include "MSIMysticLightControl.h"
#include "terminal.h"
#include "log.h"

HINSTANCE MysticLightInstance;

int status;

CComSafeArray<BSTR> dev;
CComSafeArray<BSTR> led;

BSTR gpu = L"MSI_VGA";


struct MysticLight {
    LPMLAPI_Initialize init;
    LPMLAPI_GetErrorMessage getErrorMessage;
    LPMLAPI_GetDeviceInfo getDeviceInfo;
    LPMLAPI_GetDeviceName getDeviceName;
    LPMLAPI_GetLedInfo getLEDInfo;
    LPMLAPI_GetLedColor getLEDColor;
    LPMLAPI_GetLedStyle	getLEDStyle;
    LPMLAPI_GetLedMaxBright getLEDMaxBright;
    LPMLAPI_GetLedBright getLEDBright;
    LPMLAPI_GetLedMaxSpeed getLEDMaxSpeed;
    LPMLAPI_GetLedSpeed getLEDSpeed;
    LPMLAPI_SetLedColor setLEDColor;
    LPMLAPI_SetLedStyle setLEDStyle;
    LPMLAPI_SetLedBright setLEDBright;
    LPMLAPI_SetLedSpeed setLEDSpeed;
} mysticLight;

struct Color {
    DWORD r;
    DWORD g;
    DWORD b;
};

Color red = {100, 0, 0};
Color blue = {0, 100, 0};
Color green = {0, 0, 100};

int loadDLL(void) {
    // Was used for getting current dir due to DLL loading issues.
    // CAN BE REMOVED
    // TCHAR pwd[MAX_PATH];
    // GetCurrentDirectory(MAX_PATH,pwd);
    // std::wcout << pwd << std::endl;

    // Try catch loop for loading SDK .dll file.
    // Used for loading the appropriate dll for 32 or 64 bit compilation.

    try {
        MysticLightInstance = LoadLibrary(_T("../include/MysticLight/MysticLight_SDK_x64.dll"));
        if(!MysticLightInstance) {
            throw 1;
        }
    } catch(int catchNo) {
        Log::warning("MysticLight_SDK_x64.dll could not be loaded, loading 32-bit version.");
        MysticLightInstance = LoadLibrary(_T("../include/MysticLight/MysticLight_SDK.dll"));
    }

    if(!MysticLightInstance) {
        return 0;
    }

    // Setting the GetProcAddress for each DLL function to be later called.

    mysticLight.init = (LPMLAPI_Initialize)GetProcAddress(MysticLightInstance, "MLAPI_Initialize");
    mysticLight.getErrorMessage = (LPMLAPI_GetErrorMessage)GetProcAddress(MysticLightInstance, "MLAPI_GetErrorMessage");
    mysticLight.getDeviceInfo = (LPMLAPI_GetDeviceInfo)GetProcAddress(MysticLightInstance, "MLAPI_GetDeviceInfo");
    mysticLight.getDeviceName = (LPMLAPI_GetDeviceName)GetProcAddress(MysticLightInstance, "MLAPI_GetDeviceName");
    mysticLight.getLEDInfo = (LPMLAPI_GetLedInfo)GetProcAddress(MysticLightInstance, "MLAPI_GetLedInfo");
    mysticLight.getLEDColor = (LPMLAPI_GetLedColor)GetProcAddress(MysticLightInstance, "MLAPI_GetLedColor");
    mysticLight.getLEDStyle = (LPMLAPI_GetLedStyle)GetProcAddress(MysticLightInstance, "MLAPI_GetLedStyle");
    mysticLight.getLEDMaxBright = (LPMLAPI_GetLedMaxBright)GetProcAddress(MysticLightInstance, "MLAPI_GetLedMaxBright");
    mysticLight.getLEDBright = (LPMLAPI_GetLedBright)GetProcAddress(MysticLightInstance, "MLAPI_GetLedBright");
    mysticLight.getLEDMaxSpeed = (LPMLAPI_GetLedMaxSpeed)GetProcAddress(MysticLightInstance, "MLAPI_GetLedMaxSpeed");
    mysticLight.getLEDSpeed = (LPMLAPI_GetLedSpeed)GetProcAddress(MysticLightInstance, "MLAPI_GetLedSpeed");
    mysticLight.setLEDColor = (LPMLAPI_SetLedColor)GetProcAddress(MysticLightInstance, "MLAPI_SetLedColor");
    mysticLight.setLEDStyle = (LPMLAPI_SetLedStyle)GetProcAddress(MysticLightInstance, "MLAPI_SetLedStyle");
    mysticLight.setLEDBright = (LPMLAPI_SetLedBright)GetProcAddress(MysticLightInstance, "MLAPI_SetLedBright");
    mysticLight.setLEDSpeed = (LPMLAPI_SetLedSpeed)GetProcAddress(MysticLightInstance, "MLAPI_SetLedSpeed");

    return 1;
}

int MSI::unloadDLL() {
    FreeLibrary(MysticLightInstance);
    return 0;
}

std::wstring statusMessage(int status_i) {
    BSTR statusStr;
    mysticLight.getErrorMessage(status_i, &statusStr);
    return statusStr;
}

std::wstring convertBSTRtoWString(BSTR bs) {
    assert(bs != nullptr);
    std::wstring ws(bs, SysStringLen(bs));
    return ws;
}

int main(int argc, char** argv) {
    Log::info("Started MSIMysticLightService");
//    Terminal terminal(1);
    std::ostringstream devLedMessage;
    Log::init();
    if(loadDLL()) {
//        terminal.showOptions(0, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
        Log::info("MysticLight_SDK.dll has been found and loaded.");
        status = mysticLight.init();
        if(status == 0) {
            Log::info(statusMessage(status));
            Log::info("Device Initialised.");
            statusMessage(mysticLight.getDeviceInfo(&(dev.m_psa), &(led.m_psa)));
            for(LONG i = dev.GetLowerBound(); i <= dev.GetUpperBound(); i++) {
                devLedMessage << "Device #" << i << ":" << convertBSTRtoWString(dev.GetAt(i)).c_str() << ", LED Count: " << convertBSTRtoWString(led.GetAt(i)).c_str();
                Log::debug(std::to_string(i));
//                std::printf("Device #%S:, LED Count:%S\n", ,  led.GetAt(i));
            }
            Log::debug(devLedMessage.str());
            Color getColor{};
            Log::debug(statusMessage(mysticLight.getLEDColor(dev.GetAt(0), 1, &getColor.r, &getColor.g, &getColor.b)));
            Log::debug(((std::ostringstream) "" << "Red: " << getColor.r << " Green: " << getColor.g << " Blue: " << getColor.b).str());
        } else {
            Log::error(statusMessage(status));
            return -1;
        }
    } else {
        Log::error("MysticLight_SDK not found.\n");
        MSI::unloadDLL();
        return -1;
    }
    MSI::unloadDLL();
//    system("PAUSE");
    return 0;
}
