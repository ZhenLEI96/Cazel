#pragma once
#include "Core.h"
namespace Cazel {
	class CAZEL_API Application
	{
	public:
		Application(); // ���캯�������ڳ�ʼ��Ӧ�ó���ʵ��
		virtual ~Application(); // ������������ȷ�������������ȷ�ͷ���Դ
		void run(); // ��ѭ������������Ӧ�ó���
	};
	// to be defined in CLIENT
	Application* CreateApplication();
}


