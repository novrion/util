#include <windows.h>



void SetWindowBlur(HWND hWnd) {

	const HINSTANCE hModule = LoadLibrary(TEXT("user32.dll"));

	if (hModule) {

		struct ACCENTPOLICY {

			int nAccentState;
			int nFlags;
			int nColor;
			int nAnimationId;
		};

		struct WINCOMPATTRDATA {

			int nAttribute;
			PVOID pData;
			ULONG ulDataSize;
		};

		typedef BOOL(WINAPI*pSetWindowCompositionAttribute)(HWND, WINCOMPATTRDATA*);

		const pSetWindowCompositionAttribute SetWindowCompositionAttribute = (pSetWindowCompositionAttribute)GetProcAddress(hModule, "SetWindowCompositionAttribute");

		if (SetWindowCompositionAttribute) {

			ACCENTPOLICY policy = { 3, 0, 0, 0 }; // ACCENT_ENABLE_BLURBEHIND=3...
			WINCOMPATTRDATA data = { 19, &policy, sizeof(ACCENTPOLICY) }; // WCA_ACCENT_POLICY=19
			SetWindowCompositionAttribute(hWnd, &data);
		}

		FreeLibrary(hModule);
	}
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR pCmdLine, int nCmdShow) {

	HWND taskbar = FindWindow("Shell_TrayWnd", NULL);
	
	
	while (true) {

		SetWindowBlur(taskbar);
    Sleep(10);
	}
}