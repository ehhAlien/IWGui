# IWGui

### information
• Call Modern Warfare 2 Graphics Functions With Ease In this Precompiled Library.<br>
• All In One Library. No Need To Search For Graphics Addresses for MW2 ( MP / SP ) I will keep it updated for you.


#### Installation
Place "iwgui\iw4.h" file in directory for visual studio or ide you currently use.<br>
Place "gui.lib" file in directory for visual studio or ide you currently use.<br>

#### Example ( Header Installation )
```cpp
iwgui\iw4.h -> "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Tools\MSVC\14.22.27905\include\iwgui\iw4.h" # Visual Studio 2019
```
### Example ( library Installation )
```cpp
gui.lib -> "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Tools\MSVC\14.22.27905\lib\x86\gui.lib" # Visual Studio 2019
```

### How To Setup ( Example )
```cpp


// Notice: to compile set library linker gui.lib in Properties->Linker->input->Additional Dependencies->gui.lib; 

const float colorWhite[4] = { 1.0, 1.0, 1.0, 1.0 };

void(*R_EndFrame)(void) = (void(*)(void))game::r_endframe;

void EndFrame(void)
{
	// example of graphics calling
	Font_s * font = R_RegisterFont("fonts/hudsmallfont", 1);
	
	R_AddCmdDrawText("IWGui IW4 MP Example", strlen("IWGui IW4 MP Example"), font, 40, 40, 0.5, 0.5, 0, colorWhite, 3);
	
	return R_EndFrame();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// initalizes IWGui for desired game type ( MP / SP )
		// notice if this is not called on attach, game process will crash as it will not have a valid load of graphics calls.
		IWGui_Init(MP);
		// frame hook used for handling graphics rendering ( Attaches Hook )
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)R_EndFrame, EndFrame);
		DetourTransactionCommit();

		break;
	case DLL_PROCESS_DETACH:
		// frame hook used for handling graphics rendering ( Detaches Hook )
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)R_EndFrame, EndFrame);
		DetourTransactionCommit();
		break;
	}
	return TRUE;
}


```
