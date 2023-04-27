#include <bits/stdc++.h>
#include <windows.h>
// #include <dir.h>
#include <conio.h>
#include <sys/stat.h>
#include <shlwapi.h>
#include <thread>
#include <dirent.h>
#include <vector>
#include <cstring>
#pragma comment(lib, "Shlwapi.lib")
#define Down(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)
using namespace std;

int pid1 = -1, pid2 = -1, kbd;
inline bool exists(const string name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}
WINBOOL HideConsole()
{
    HWND hwndc = GetConsoleWindow();
    return ShowWindow(hwndc, SW_HIDE);
}
int main()
{
    HideConsole();
    while (1)
    {
        if (Down(1))
        {
            for (int i = 0; i < 3; ++i)
            {
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            }
            sleep(1);
        }
    }
    return 0;
}