
#include "stdafx.h"

#include "../Module/Implement/ModuleBase/ModuleBase.hpp"


/**
* @brief ģ��ʵ��ʾ��
*/

BEGIN_DECLARE_MODULE(ModuleABC)
/**
* @brief ģ��ʾ���ࡣ\n
*		 ģ�鶨����������BEGIN_DECLARE_MODULE��END_DECLARE_MODULE������֮�䣻	��д����ǰ����ʹ�ú�IMPLEMENT_MODULE_BASE�Ը�ģ������ж��壻\n
*		 ģ����밴����ģʽʵ�֣�ʵ�ָ�ʽ���������һ�¡�
*/

class ModuleABC :public ModuleBase
{
	IMPLEMENT_MODULE_BASE(ModuleABC)

public:
	/**
	* @brief ��ʼ����ģ������������ڼ���ģ�����֮ǰ���ô˺�����
	*		 ģ�������ʵ�ִ˺�����
	* @return 0Ϊ��ʼ���ɹ�����0Ϊʧ�ܡ�
	*/
	int Initialize() override;

	/**
	* @brief ����ʼ����ģ�������������ж��ģ�����֮ǰ���ô˺�����
	*		 ģ�������ʵ�ִ˺�����
	*/
	void Uninitialize() override;

	/**
	* @brief ��ȡģ���ID��ʵ��ģ����ʱ�������ȵ�/src/Module/Implement/PubDef.h�ļ��ж����ģ�����ID���Ա�ģ�����������ʶ��
	*		 ģ�������ʵ�ִ˺�����
	* @return ģ��ID
	*/
	int GetID() override;

	/**
	* @brief ��ȡģ������ָ�룬�Ա�ģ����������м��أ�
	*		 ģ�������ʵ�ִ˺�����
	* @return ģ�����ָ��
	*/
	IPlugin* GetModulePtr() override;

	/**
	* @brief ��ȡģ������ƣ��Ա�ģ�����������ʶ�𣻴����Ʊ���ΪDLL�����֣�
	*		 ģ�������ʵ�ִ˺�����
	* @return ģ������
	*/
	std::wstring GetName() override;

	/**
	* @brief ��ȡģ��İ汾���Ա�ģ�����������������
	*		 ģ�������ʵ�ִ˺�����
	* @return ģ������
	*/
	int GetVersion() override;

	/**
	* @brief ��Ϣ��Ӧ����ʾ����ʾ���˶�̬����Ϣ�Լ�������Ϣ�ķ�����
	* @param[in] param1 ��Ϣ����1
	* @param[in] param2 ��Ϣ����2
	* @param[in] senderID ������ID
	*/
	void OnModuleInit(int param1, int param2, int senderID);
	void OnMessageTest1(int param1, int param2, int senderID);

	static ModuleABC* Instance();



private:
	ModuleABC(){};
	~ModuleABC();

	static ModuleABC* _instance;
};

ModuleABC* ModuleABC::_instance = nullptr;

END_DECLARE_MODULE(ModuleABC)
