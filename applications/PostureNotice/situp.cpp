// g++ -O2 -o run .\situp.cpp -L./C:/Windows/SysWOW64 -lwinmm -mwindows

#include <windows.h>
#include <mmsystem.h>
#include <algorithm>

#pragma comment(lib, "winmm.lib")


const char* SOUNDPATH = "wav\\notice.wav";



inline void sound( const char* path ) {
  PlaySound( path, NULL, SND_FILENAME | SND_ASYNC );
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR pCmdLine, int nCmdShow) {

  while (true) {

    sound(SOUNDPATH);
    Sleep(1200000);
  }





  return 0;
}