#include <stdio.h>
#include <windows.h>

#include "DarkReignPatch.h"
#pragma pack(1)


HINSTANCE hLThis = 0;
HINSTANCE hL = 0;
FARPROC p[112] = { 0 };

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		hLThis = hInst;
		hL = LoadLibrary("anet2_.dll");
		if (!hL) return false;


		const char* exportNames[] = { "_daa", "_dab", "_dac", "_dad", "_dae", "_daf", "_dag", "_dah", "_dai",
									  "_daj", "_dak", "_dal", "_dam", "_dan", "_dao", "_daoot", "_dap", "_daq",
									  "_dar", "_darr", "_das", "_dat", "_dau", "_dav", "_daw", "_dax", "_dax7",
									  "_dax8", "_dax9", "_day", "_daz", "_dpbs",
									  "dpAddPlayerToGroup", "dpCastoffSession", "dpCheckAppVersion", "dpClose",
									  "dpCloseGameServer", "dpCommThaw", "dpCreate", "dpCreateGroup", "dpCreatePlayer", 
									  "dpDeclareLobby", "dpDeletePlayerFromGroup", "dpDestroy", "dpDestroyGroup",  "dpDestroyPlayer",
									  "dpDownloadUpdate",  "dpEnableNewPlayers", "dpEnumApp", "dpEnumGroupPlayers", "dpEnumGroups",
									  "dpEnumPlayers", "dpEnumPlayersEx", "dpEnumPorts", "dpEnumServers", "dpEnumServersEx",  "dpEnumSessions",
									  "dpEnumTransports", "dpFreeze", "dpGetAppVersion", "dpGetCaps", "dpGetParameterLong",
									  "dpGetPlayerBlob", "dpGetPlayerCaps", "dpGetPlayerData", "dpGetPlayerName", "dpGetSessionDesc",
									  "dpGetSessionId", "dpGetStats", "dpGetTransportInfo", "dpLaunchApp", "dpLaunchApp2",
									  "dpNumPlayers", "dpOpen", "dpPingUser", "dpReadAnetInf", "dpReadyToFreeze", "dpReceive",
									  "dpReportAssertionFailure",  "dpReportCrash", "dpReportCrashEx", "dpReportScore", "dpRequestObjectDeltas",
									  "dpResolveHostname", "dpSend", "dpSendPlayerData", "dpSetConnCallback", "dpSetGameServer",
									  "dpSetGameServerEx", "dpSetPlayerBlob", "dpSetPlayerData", "dpSetPlayerName", "dpSetSessionDesc",
									  "dpTurnFinish", "dpTurnGetMove", "dpTurnInit", "dpTurnPoll", "dpTurnPutMove", "dp_dprintf",
									  "dp_enableDebugPrint", "dp_flushLog", "dp_pack_session", "dp_setLogFname", "dp_unpack_session",
									  "dpini_GetFile", "dpini_SetFile", "dpini_findSection", "dpini_readParameter", "dptab_changePublisher",
									  "dptab_getTableContext", "dptab_tableRef_freeze", "dptab_tableRef_thaw", 0 };
		
		for (int i = 0; exportNames[i]; i++)
			p[i] = GetProcAddress(hL, exportNames[i]);
		
		DWORD threadId = 0;
		HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)InitialisePatch, NULL, 0, &threadId);
	}
	if (reason == DLL_PROCESS_DETACH)
	{
		FreeLibrary(hL);
	}

	return 1;
}

// _daa
extern "C" __declspec(naked) void _stdcall __E__0__()
{
	__asm
	{
		jmp p[0 * 4];
	}
}

// _dab
extern "C" __declspec(naked) void _stdcall __E__1__()
{
	__asm
	{
		jmp p[1 * 4];
	}
}

// _dac
extern "C" __declspec(naked) void _stdcall __E__2__()
{
	__asm
	{
		jmp p[2 * 4];
	}
}

// _dad
extern "C" __declspec(naked) void _stdcall __E__3__()
{
	__asm
	{
		jmp p[3 * 4];
	}
}

// _dae
extern "C" __declspec(naked) void _stdcall __E__4__()
{
	__asm
	{
		jmp p[4 * 4];
	}
}

// _daf
extern "C" __declspec(naked) void _stdcall __E__5__()
{
	__asm
	{
		jmp p[5 * 4];
	}
}

// _dag
extern "C" __declspec(naked) void _stdcall __E__6__()
{
	__asm
	{
		jmp p[6 * 4];
	}
}

// _dah
extern "C" __declspec(naked) void _stdcall __E__7__()
{
	__asm
	{
		jmp p[7 * 4];
	}
}

// _dai
extern "C" __declspec(naked) void _stdcall __E__8__()
{
	__asm
	{
		jmp p[8 * 4];
	}
}

// _daj
extern "C" __declspec(naked) void _stdcall __E__9__()
{
	__asm
	{
		jmp p[9 * 4];
	}
}

// _dak
extern "C" __declspec(naked) void _stdcall __E__10__()
{
	__asm
	{
		jmp p[10 * 4];
	}
}

// _dal
extern "C" __declspec(naked) void _stdcall __E__11__()
{
	__asm
	{
		jmp p[11 * 4];
	}
}

// _dam
extern "C" __declspec(naked) void _stdcall __E__12__()
{
	__asm
	{
		jmp p[12 * 4];
	}
}

// _dan
extern "C" __declspec(naked) void _stdcall __E__13__()
{
	__asm
	{
		jmp p[13 * 4];
	}
}

// _dao
extern "C" __declspec(naked) void _stdcall __E__14__()
{
	__asm
	{
		jmp p[14 * 4];
	}
}

// _daoot
extern "C" __declspec(naked) void _stdcall __E__15__()
{
	__asm
	{
		jmp p[15 * 4];
	}
}

// _dap
extern "C" __declspec(naked) void _stdcall __E__16__()
{
	__asm
	{
		jmp p[16 * 4];
	}
}

// _daq
extern "C" __declspec(naked) void _stdcall __E__17__()
{
	__asm
	{
		jmp p[17 * 4];
	}
}

// _dar
extern "C" __declspec(naked) void _stdcall __E__18__()
{
	__asm
	{
		jmp p[18 * 4];
	}
}

// _darr
extern "C" __declspec(naked) void _stdcall __E__19__()
{
	__asm
	{
		jmp p[19 * 4];
	}
}

// _das
extern "C" __declspec(naked) void _stdcall __E__20__()
{
	__asm
	{
		jmp p[20 * 4];
	}
}

// _dat
extern "C" __declspec(naked) void _stdcall __E__21__()
{
	__asm
	{
		jmp p[21 * 4];
	}
}

// _dau
extern "C" __declspec(naked) void _stdcall __E__22__()
{
	__asm
	{
		jmp p[22 * 4];
	}
}

// _dav
extern "C" __declspec(naked) void _stdcall __E__23__()
{
	__asm
	{
		jmp p[23 * 4];
	}
}

// _daw
extern "C" __declspec(naked) void _stdcall __E__24__()
{
	__asm
	{
		jmp p[24 * 4];
	}
}

// _dax
extern "C" __declspec(naked) void _stdcall __E__25__()
{
	__asm
	{
		jmp p[25 * 4];
	}
}

// _dax7
extern "C" __declspec(naked) void _stdcall __E__26__()
{
	__asm
	{
		jmp p[26 * 4];
	}
}

// _dax8
extern "C" __declspec(naked) void _stdcall __E__27__()
{
	__asm
	{
		jmp p[27 * 4];
	}
}

// _dax9
extern "C" __declspec(naked) void _stdcall __E__28__()
{
	__asm
	{
		jmp p[28 * 4];
	}
}

// _day
extern "C" __declspec(naked) void _stdcall __E__29__()
{
	__asm
	{
		jmp p[29 * 4];
	}
}

// _daz
extern "C" __declspec(naked) void _stdcall __E__30__()
{
	__asm
	{
		jmp p[30 * 4];
	}
}

// _dpbs
extern "C" __declspec(naked) void _stdcall __E__31__()
{
	__asm
	{
		jmp p[31 * 4];
	}
}

// dpAddPlayerToGroup
extern "C" __declspec(naked) void _stdcall __E__32__()
{
	__asm
	{
		jmp p[32 * 4];
	}
}

// dpCastoffSession
extern "C" __declspec(naked) void _stdcall __E__33__()
{
	__asm
	{
		jmp p[33 * 4];
	}
}

// dpCheckAppVersion
extern "C" __declspec(naked) void _stdcall __E__34__()
{
	__asm
	{
		jmp p[34 * 4];
	}
}

// dpClose
extern "C" __declspec(naked) void _stdcall __E__35__()
{
	__asm
	{
		jmp p[35 * 4];
	}
}

// dpCloseGameServer
extern "C" __declspec(naked) void _stdcall __E__36__()
{
	__asm
	{
		jmp p[36 * 4];
	}
}

// dpCommThaw
extern "C" __declspec(naked) void _stdcall __E__37__()
{
	__asm
	{
		jmp p[37 * 4];
	}
}

// dpCreate
extern "C" __declspec(naked) void _stdcall __E__38__()
{
	__asm
	{
		jmp p[38 * 4];
	}
}

// dpCreateGroup
extern "C" __declspec(naked) void _stdcall __E__39__()
{
	__asm
	{
		jmp p[39 * 4];
	}
}

// dpCreatePlayer
extern "C" __declspec(naked) void _stdcall __E__40__()
{
	__asm
	{
		jmp p[40 * 4];
	}
}

// dpDeclareLobby
extern "C" __declspec(naked) void _stdcall __E__41__()
{
	__asm
	{
		jmp p[41 * 4];
	}
}

// dpDeletePlayerFromGroup
extern "C" __declspec(naked) void _stdcall __E__42__()
{
	__asm
	{
		jmp p[42 * 4];
	}
}

// dpDestroy
extern "C" __declspec(naked) void _stdcall __E__43__()
{
	__asm
	{
		jmp p[43 * 4];
	}
}

// dpDestroyGroup
extern "C" __declspec(naked) void _stdcall __E__44__()
{
	__asm
	{
		jmp p[44 * 4];
	}
}

// dpDestroyPlayer
extern "C" __declspec(naked) void _stdcall __E__45__()
{
	__asm
	{
		jmp p[45 * 4];
	}
}

// dpDownloadUpdate
extern "C" __declspec(naked) void _stdcall __E__46__()
{
	__asm
	{
		jmp p[46 * 4];
	}
}

// dpEnableNewPlayers
extern "C" __declspec(naked) void _stdcall __E__47__()
{
	__asm
	{
		jmp p[47 * 4];
	}
}

// dpEnumApp
extern "C" __declspec(naked) void _stdcall __E__48__()
{
	__asm
	{
		jmp p[48 * 4];
	}
}

// dpEnumGroupPlayers
extern "C" __declspec(naked) void _stdcall __E__49__()
{
	__asm
	{
		jmp p[49 * 4];
	}
}

// dpEnumGroups
extern "C" __declspec(naked) void _stdcall __E__50__()
{
	__asm
	{
		jmp p[50 * 4];
	}
}

// dpEnumPlayers
extern "C" __declspec(naked) void _stdcall __E__51__()
{
	__asm
	{
		jmp p[51 * 4];
	}
}

// dpEnumPlayersEx
extern "C" __declspec(naked) void _stdcall __E__52__()
{
	__asm
	{
		jmp p[52 * 4];
	}
}

// dpEnumPorts
extern "C" __declspec(naked) void _stdcall __E__53__()
{
	__asm
	{
		jmp p[53 * 4];
	}
}

// dpEnumServers
extern "C" __declspec(naked) void _stdcall __E__54__()
{
	__asm
	{
		jmp p[54 * 4];
	}
}

// dpEnumServersEx
extern "C" __declspec(naked) void _stdcall __E__55__()
{
	__asm
	{
		jmp p[55 * 4];
	}
}

// dpEnumSessions
extern "C" __declspec(naked) void _stdcall __E__56__()
{
	__asm
	{
		jmp p[56 * 4];
	}
}

// dpEnumTransports
extern "C" __declspec(naked) void _stdcall __E__57__()
{
	__asm
	{
		jmp p[57 * 4];
	}
}

// dpFreeze
extern "C" __declspec(naked) void _stdcall __E__58__()
{
	__asm
	{
		jmp p[58 * 4];
	}
}

// dpGetAppVersion
extern "C" __declspec(naked) void _stdcall __E__59__()
{
	__asm
	{
		jmp p[59 * 4];
	}
}

// dpGetCaps
extern "C" __declspec(naked) void _stdcall __E__60__()
{
	__asm
	{
		jmp p[60 * 4];
	}
}

// dpGetParameterLong
extern "C" __declspec(naked) void _stdcall __E__61__()
{
	__asm
	{
		jmp p[61 * 4];
	}
}

// dpGetPlayerBlob
extern "C" __declspec(naked) void _stdcall __E__62__()
{
	__asm
	{
		jmp p[62 * 4];
	}
}

// dpGetPlayerCaps
extern "C" __declspec(naked) void _stdcall __E__63__()
{
	__asm
	{
		jmp p[63 * 4];
	}
}

// dpGetPlayerData
extern "C" __declspec(naked) void _stdcall __E__64__()
{
	__asm
	{
		jmp p[64 * 4];
	}
}

// dpGetPlayerName
extern "C" __declspec(naked) void _stdcall __E__65__()
{
	__asm
	{
		jmp p[65 * 4];
	}
}

// dpGetSessionDesc
extern "C" __declspec(naked) void _stdcall __E__66__()
{
	__asm
	{
		jmp p[66 * 4];
	}
}

// dpGetSessionId
extern "C" __declspec(naked) void _stdcall __E__67__()
{
	__asm
	{
		jmp p[67 * 4];
	}
}

// dpGetStats
extern "C" __declspec(naked) void _stdcall __E__68__()
{
	__asm
	{
		jmp p[68 * 4];
	}
}

// dpGetTransportInfo
extern "C" __declspec(naked) void _stdcall __E__69__()
{
	__asm
	{
		jmp p[69 * 4];
	}
}

// dpLaunchApp
extern "C" __declspec(naked) void _stdcall __E__70__()
{
	__asm
	{
		jmp p[70 * 4];
	}
}

// dpLaunchApp2
extern "C" __declspec(naked) void _stdcall __E__71__()
{
	__asm
	{
		jmp p[71 * 4];
	}
}

// dpNumPlayers
extern "C" __declspec(naked) void _stdcall __E__72__()
{
	__asm
	{
		jmp p[72 * 4];
	}
}

// dpOpen
extern "C" __declspec(naked) void _stdcall __E__73__()
{
	__asm
	{
		jmp p[73 * 4];
	}
}

// dpPingUser
extern "C" __declspec(naked) void _stdcall __E__74__()
{
	__asm
	{
		jmp p[74 * 4];
	}
}

// dpReadAnetInf
extern "C" __declspec(naked) void _stdcall __E__75__()
{
	__asm
	{
		jmp p[75 * 4];
	}
}

// dpReadyToFreeze
extern "C" __declspec(naked) void _stdcall __E__76__()
{
	__asm
	{
		jmp p[76 * 4];
	}
}

// dpReceive
extern "C" __declspec(naked) void _stdcall __E__77__()
{
	__asm
	{
		jmp p[77 * 4];
	}
}

// dpReportAssertionFailure
extern "C" __declspec(naked) void _stdcall __E__78__()
{
	__asm
	{
		jmp p[78 * 4];
	}
}

// dpReportCrash
extern "C" __declspec(naked) void _stdcall __E__79__()
{
	__asm
	{
		jmp p[79 * 4];
	}
}

// dpReportCrashEx
extern "C" __declspec(naked) void _stdcall __E__80__()
{
	__asm
	{
		jmp p[80 * 4];
	}
}

// dpReportScore
extern "C" __declspec(naked) void _stdcall __E__81__()
{
	__asm
	{
		jmp p[81 * 4];
	}
}

// dpRequestObjectDeltas
extern "C" __declspec(naked) void _stdcall __E__82__()
{
	__asm
	{
		jmp p[82 * 4];
	}
}

// dpResolveHostname
extern "C" __declspec(naked) void _stdcall __E__83__()
{
	__asm
	{
		jmp p[83 * 4];
	}
}

// dpSend
extern "C" __declspec(naked) void _stdcall __E__84__()
{
	__asm
	{
		jmp p[84 * 4];
	}
}

// dpSendPlayerData
extern "C" __declspec(naked) void _stdcall __E__85__()
{
	__asm
	{
		jmp p[85 * 4];
	}
}

// dpSetConnCallback
extern "C" __declspec(naked) void _stdcall __E__86__()
{
	__asm
	{
		jmp p[86 * 4];
	}
}

// dpSetGameServer
extern "C" __declspec(naked) void _stdcall __E__87__()
{
	__asm
	{
		jmp p[87 * 4];
	}
}

// dpSetGameServerEx
extern "C" __declspec(naked) void _stdcall __E__88__()
{
	__asm
	{
		jmp p[88 * 4];
	}
}

// dpSetPlayerBlob
extern "C" __declspec(naked) void _stdcall __E__89__()
{
	__asm
	{
		jmp p[89 * 4];
	}
}

// dpSetPlayerData
extern "C" __declspec(naked) void _stdcall __E__90__()
{
	__asm
	{
		jmp p[90 * 4];
	}
}

// dpSetPlayerName
extern "C" __declspec(naked) void _stdcall __E__91__()
{
	__asm
	{
		jmp p[91 * 4];
	}
}

// dpSetSessionDesc
extern "C" __declspec(naked) void _stdcall __E__92__()
{
	__asm
	{
		jmp p[92 * 4];
	}
}

// dpTurnFinish
extern "C" __declspec(naked) void _stdcall __E__93__()
{
	__asm
	{
		jmp p[93 * 4];
	}
}

// dpTurnGetMove
extern "C" __declspec(naked) void _stdcall __E__94__()
{
	__asm
	{
		jmp p[94 * 4];
	}
}

// dpTurnInit
extern "C" __declspec(naked) void _stdcall __E__95__()
{
	__asm
	{
		jmp p[95 * 4];
	}
}

// dpTurnPoll
extern "C" __declspec(naked) void _stdcall __E__96__()
{
	__asm
	{
		jmp p[96 * 4];
	}
}

// dpTurnPutMove
extern "C" __declspec(naked) void _stdcall __E__97__()
{
	__asm
	{
		jmp p[97 * 4];
	}
}

// dp_dprintf
extern "C" __declspec(naked) void _stdcall __E__98__()
{
	__asm
	{
		jmp p[98 * 4];
	}
}

// dp_enableDebugPrint
extern "C" __declspec(naked) void _stdcall __E__99__()
{
	__asm
	{
		jmp p[99 * 4];
	}
}

// dp_flushLog
extern "C" __declspec(naked) void _stdcall __E__100__()
{
	__asm
	{
		jmp p[100 * 4];
	}
}

// dp_pack_session
extern "C" __declspec(naked) void _stdcall __E__101__()
{
	__asm
	{
		jmp p[101 * 4];
	}
}

// dp_setLogFname
extern "C" __declspec(naked) void _stdcall __E__102__()
{
	__asm
	{
		jmp p[102 * 4];
	}
}

// dp_unpack_session
extern "C" __declspec(naked) void _stdcall __E__103__()
{
	__asm
	{
		jmp p[103 * 4];
	}
}

// dpini_GetFile
extern "C" __declspec(naked) void _stdcall __E__104__()
{
	__asm
	{
		jmp p[104 * 4];
	}
}

// dpini_SetFile
extern "C" __declspec(naked) void _stdcall __E__105__()
{
	__asm
	{
		jmp p[105 * 4];
	}
}

// dpini_findSection
extern "C" __declspec(naked) void _stdcall __E__106__()
{
	__asm
	{
		jmp p[106 * 4];
	}
}

// dpini_readParameter
extern "C" __declspec(naked) void _stdcall __E__107__()
{
	__asm
	{
		jmp p[107 * 4];
	}
}

// dptab_changePublisher
extern "C" __declspec(naked) void _stdcall __E__108__()
{
	__asm
	{
		jmp p[108 * 4];
	}
}

// dptab_getTableContext
extern "C" __declspec(naked) void _stdcall __E__109__()
{
	__asm
	{
		jmp p[109 * 4];
	}
}

// dptab_tableRef_freeze
extern "C" __declspec(naked) void _stdcall __E__110__()
{
	__asm
	{
		jmp p[110 * 4];
	}
}

// dptab_tableRef_thaw
extern "C" __declspec(naked) void _stdcall __E__111__()
{
	__asm
	{
		jmp p[111 * 4];
	}
}

