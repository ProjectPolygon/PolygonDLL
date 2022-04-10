#pragma once

#include "RobloxMFCClasses.h"

// Type Definitions //

typedef BOOL(__thiscall* Http__trustCheck_t)(int _this, const char* url);
#ifdef OUTPUT
typedef void(__thiscall* StandardOut__print_t)(int _this, int type, std::string* message);
#endif

// Hook Declarations //

BOOL __fastcall Http__trustCheck_hook(int _this, void*, const char* url);
#ifdef OUTPUT
void __fastcall StandardOut__print_hook(int _this, void*, int type, std::string* message);
#endif

// Externals //

extern Http__trustCheck_t Http__trustCheck;
#ifdef OUTPUT
extern StandardOut__print_t StandardOut__print;
#endif
