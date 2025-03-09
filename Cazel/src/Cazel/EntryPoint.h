#pragma once // ��ֹͷ�ļ��ظ�����

// ����ȫ�ֺ��� CreateApplication������ܵ����Դ����û��Զ����Ӧ�ó���ʵ��
// �Ż����飺������ֵ��Ϊ std::unique_ptr<Application>���Ա����ֶ������ڴ档
extern Cazel::Application* Cazel::CreateApplication();

// main �������������ڵ�
int main(int argc, char** argv)
{
    Cazel::Log::Init(); // ��ʼ����־ϵͳ
    CZ_CORE_WARN("Initialized Log!"); // �������ģ��ľ�����Ϣ

    int a = 5; // ����һ����������
    CZ_CLIENT_INFO("Hello! Var = {0}", a); // ����ͻ���ģ�����Ϣ��־

    // �����û��Զ����Ӧ�ó���ʵ��
    // �Ż����飺ʹ������ָ�루�� std::unique_ptr��������ָ�룬�����ֶ������ڴ档
    auto app = Cazel::CreateApplication();

    app->run(); // ����Ӧ�ó������ѭ��

    delete app; // �ͷŶ�̬������ڴ�
    // �Ż����飺���ʹ������ָ�룬���ﲻ��Ҫ�ֶ����� delete��
}

