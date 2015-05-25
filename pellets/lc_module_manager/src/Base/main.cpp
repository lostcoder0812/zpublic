#include "windows.h"
#include <string>


int main()
{
	HMODULE tmp = LoadLibrary(L"ModuleManager.dll");

	bool(*fnLoadPlugin)(std::wstring path) = (bool(*)(std::wstring path)) GetProcAddress(tmp, "LoadPlugin");
	// ģ�����ƣ���ʱ�������
	fnLoadPlugin(L"ModuleSample.dll");

	void(*fnBeginLoop)() = (void(*)())GetProcAddress(tmp, "BeginMessageLoop");

	fnBeginLoop();

	return 0;
}
