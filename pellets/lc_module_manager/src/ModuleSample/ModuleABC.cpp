// ModuleSample.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ModuleABC.h"



// ��̬����Ϣ����ģ���ʼ��ʱ���ذ�
BEGIN_MESSAGE_MAP(ModuleABC)
	DEFINE_MESSAGE_BINDING(Msg_Module_Initialzed, &OnModuleInit)
END_MESSAGE_MAP

int ModuleABC::GetID()
{
	return ModuleDefine::Module_ModuleABC;
}

std::wstring ModuleABC::GetName()
{
	return L"ModuleABC";
}

int ModuleABC::Initialize()
{
	return 0;
}

void ModuleABC::Uninitialize()
{

}

int ModuleABC::GetVersion()
{
	return 1;
}

IPlugin* ModuleABC::GetModulePtr()
{
	return _instance;
}

void ModuleABC::OnModuleInit(int param1, int param2, int senderID)
{
	UNREFERENCED_PARAMETER(param2);
	UNREFERENCED_PARAMETER(senderID);

	// ��̬����Ϣ����ģ�����й����м��ذ�
	BindMessage(Msg_Test_1, &ModuleABC::OnMessageTest1);

	// ������Ϣ
	ProduceMessage(this->GetID(), Msg_Test_1, param1, reinterpret_cast<int>(L"HI"));
}

void ModuleABC::OnMessageTest1(int param1, int param2, int senderID)
{
	UNREFERENCED_PARAMETER(param2);
	UNREFERENCED_PARAMETER(senderID);

	ProduceMessage(this->GetID(), Msg_Test_2, param1, reinterpret_cast<int>(L"HI"));
}

ModuleABC* ModuleABC::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new ModuleABC();
	}

	return _instance;
}

ModuleABC::~ModuleABC()
{
	delete _instance;
}
