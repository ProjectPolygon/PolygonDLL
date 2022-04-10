#pragma once

#define OUTPUT

// so 2012's a bit different
// VMProtect likes to offset the memory locations randomly on startup
// so defining the addresses here are a bit weird
	
// say the beginning of the program is located at 0x00BF1000
// and you have a trust check hook that's, for example, located at 0x00DF20A0

// VMProtect is offsetting the memory location from 0x00000000 - 0x00FF0000
// so the 0x00BF0000 in 0x00BF1000 is actually an offset

// with that offset, the address you'd have to put for your trust check hook will be 0x00DF20A0 - 0x00BF0000 = 0x002020A0
// and you just put that address into the function

#define ADDRESS_HTTP__TRUSTCHECK                   0x005CD760 //Patches::GetAddressByOffset(0x002020A0)
#define ADDRESS_CRYPT__VERIFYSIGNATUREBASE64       0x00B6C9E0 //Patches::GetAddressByOffset(0x00526330)
#define ADDRESS_STANDARDOUT__PRINT                 0x005E3330