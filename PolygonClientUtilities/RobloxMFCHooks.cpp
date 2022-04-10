#include "pch.h"
#include "RobloxMFCHooks.h"
#include "Patches.h"
#include "Config.h"
#include "Util.h"
#include "LUrlParser.h"
#include "Logger.h"

// Functions //

Http__trustCheck_t Http__trustCheck = (Http__trustCheck_t)ADDRESS_HTTP__TRUSTCHECK;
#ifdef OUTPUT
StandardOut__print_t StandardOut__print = (StandardOut__print_t)ADDRESS_STANDARDOUT__PRINT;
#endif

// Hook Definitions //

BOOL __fastcall Http__trustCheck_hook(int _this, void*, const char* url)
{
    LUrlParser::ParseURL parsedUrl = LUrlParser::ParseURL::parseURL(url);

    if (!parsedUrl.isValid())
        return false;

    if (std::string("about:blank") == url)
        return true;

    if (std::find(Util::allowedSchemes.begin(), Util::allowedSchemes.end(), parsedUrl.scheme_) != Util::allowedSchemes.end())
        return std::find(Util::allowedHosts.begin(), Util::allowedHosts.end(), parsedUrl.host_) != Util::allowedHosts.end();

    if (std::find(Util::allowedEmbeddedSchemes.begin(), Util::allowedEmbeddedSchemes.end(), parsedUrl.scheme_) != Util::allowedEmbeddedSchemes.end())
        return true; 

    return false;
}

#ifdef OUTPUT
void __fastcall StandardOut__print_hook(int _this, void*, int type, std::string* message)
{
    StandardOut__print(_this, type, message);

    if (Logger::handle)
    {
        if (!Logger::handle) return;

        switch (type)
        {
        case 1: // RBX::MESSAGE_OUTPUT:
            SetConsoleTextAttribute(Logger::handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case 0: // RBX::MESSAGE_INFO:
            SetConsoleTextAttribute(Logger::handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case 2: // RBX::MESSAGE_WARNING:
            SetConsoleTextAttribute(Logger::handle, FOREGROUND_RED | FOREGROUND_GREEN);
            break;
        case 3: // RBX::MESSAGE_ERROR:
            SetConsoleTextAttribute(Logger::handle, FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        }
        printf("%s\n", message->c_str());
        SetConsoleTextAttribute(Logger::handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
}
#endif