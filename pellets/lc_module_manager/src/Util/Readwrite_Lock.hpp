#pragma once

#include <mutex>
#include <condition_variable>

#include <windows.h>

namespace Util
{
	class Readwrite_Lock
	{
	public:
		Readwrite_Lock()
			: stat(0)
		{
		}

		void ReadLock()
		{
			while (stat < 0)
			{
				std::unique_lock<std::mutex> lock(mtx);			// д��������ʱ����
				cond.wait(lock);
			}
			InterlockedIncrement(reinterpret_cast<ULONG*>(&stat));
		}

		void ReadUnlock()
		{
			InterlockedDecrement(reinterpret_cast<ULONG*>(&stat));
			if (stat == 0)
				cond.notify_one();								// ����һ���ȴ���д����
		}

		void WriteLock()
		{
			while (stat != 0)									// ����д��������ʱ������
			{
				std::unique_lock<std::mutex> lock(mtx);
				cond.wait(lock);
			}
			InterlockedExchange(reinterpret_cast<ULONG*>(&stat), (ULONG)-1);
		}

		void WriteUnlock()
		{
			InterlockedExchange(reinterpret_cast<ULONG*>(&stat), (0));
			cond.notify_all(); // �������еȴ��Ķ���д����
		}

	private:
		std::mutex mtx;
		std::condition_variable cond;
		int stat; // == 0 ������> 0 �ѼӶ���������< 0 �Ѽ�д��
	};
}
