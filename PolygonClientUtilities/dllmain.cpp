#include "pch.h"
#include "Config.h"
#include "Patches.h"
#include "RobloxMFCHooks.h"
#include "Logger.h"

START_PATCH_LIST()
ADD_PATCH(Http__trustCheck, Http__trustCheck_hook)
#ifdef OUTPUT
ADD_PATCH(StandardOut__print, StandardOut__print_hook)
#endif
END_PATCH_LIST()

// DLLs for release will be loaded with VMProtect, so this isn't necessary
// Arbiter will still use Stud_PE for ease in swapping DLLs however
// #ifdef ARBITERBUILD
void __declspec(dllexport) import() {}
// #endif

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        LONG error = Patches::Apply();
        if (error != NO_ERROR)
        {
#ifdef _DEBUG
            std::string message = "Patches::Apply returned " + std::to_string(error);
            MessageBoxA(nullptr, message.c_str(), nullptr, MB_ICONERROR);
#endif

            ExitProcess(EXIT_FAILURE);
        }
#ifdef OUTPUT
        Logger::Initialize("output");
#endif    
    }

    return TRUE;
}