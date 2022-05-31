#pragma once

#include "Config.h"
#include <oaidl.h>

#ifdef ARBITERBUILD
struct DataModel
{
	void* padding1[CLASSPADDING_DATAMODEL__JOBID];
	std::string jobId;
};

struct Packet
{
	void* padding1[7];
	unsigned int length;
	void* padding2[1];
	unsigned char* data;
};

struct ConcurrentRakPeer {};
struct RakPeerInterface {};

struct ServerReplicator
{
	void* padding1[1869]; // offset of 0 -> 7476
	bool padding2;        // offset of 7476 -> 7477
	bool isAuthenticated; // offset of 7477 -> 7478
};
#endif

#if defined(MFC2010) || defined(MFC2011)
// 2010 struct definitions:
// 0x47E010: CWorkspace->DoExecScript()
// 0x47EC10: CWorkspace->ExecUrlScript()

class CWorkspace;

const auto CWorkspace__ExecUrlScript = (HRESULT(__stdcall*)(CWorkspace * workspace, LPCWSTR, VARIANTARG, VARIANTARG, VARIANTARG, VARIANTARG, LPVOID))ADDRESS_CWORKSPACE__EXECURLSCRIPT;

struct CRobloxDoc
{
	void* padding1[CLASSPADDING_CROBLOXDOC__WORKSPACE];
	CWorkspace* workspace;
};

struct CApp;

// const auto CApp__CreateGame = (CWorkspace * (__thiscall*)(CApp * _this, int, LPCWSTR))ADDRESS_CAPP__CREATEGAME;
const auto CApp__RobloxAuthenticate = (void * (__thiscall*)(CApp * _this, LPVOID, LPCWSTR, LPCWSTR))ADDRESS_CAPP__ROBLOXAUTHENTICATE;

// 2010 struct definitions:
// 0x405D20: CRobloxApp->CreateDocument()
// 0x44F6F0: CRobloxApp->ExitInstance()
// 0x452900: CRobloxApp->InitInstance()

struct CRobloxApp;

const auto CRobloxApp__CreateDocument = (CRobloxDoc * (__thiscall*)(CRobloxApp * _this))ADDRESS_CROBLOXAPP__CREATEDOCUMENT;

struct CCommandLineInfo
{
	void* padding1[3];
	BOOL m_bRunAutomated;
};

class CRobloxCommandLineInfo : public CCommandLineInfo {};

const auto CCommandLineInfo__ParseLast = (void(__thiscall*)(CCommandLineInfo * _this, BOOL bLast))ADDRESS_CCOMMANDLINEINFO__PARSELAST;
#endif