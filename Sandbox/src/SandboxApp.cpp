#include <Cazel.h> // ���� Cazel ��ܵĺ���ͷ�ļ������� Application ��Ȼ�������

// ���� Sandbox �࣬�̳��� Cazel::Application
// ˵����Sandbox ���û��Զ����Ӧ�ó����࣬�̳��Կ���ṩ�Ļ��� Application��
// �Ż����飺�����ڹ��캯�������������������Դ��ʼ�����ͷŵ��߼���
class Sandbox : public Cazel::Application
{
public:
    Sandbox() // ���캯�������ڳ�ʼ�� Sandbox ʵ��
    {
        // �Ż����飺��������Գ�ʼ��Ӧ�ó����������Դ�����細�ڡ���Ⱦ���ȡ�
    }
    ~Sandbox() // ���������������ͷ� Sandbox ʵ��ռ�õ���Դ
    {
        // �Ż����飺����������ͷ���Դ������ر��ļ����ͷ��ڴ�ȡ�
    }
};

// ȫ�ֺ��� CreateApplication������ܵ����Դ����û��Զ����Ӧ�ó���ʵ��
// ˵�������ǿ�ܵ���ڵ㣬��ܻ���ô˺���������������Ӧ�ó���
// �Ż����飺ʹ������ָ�루�� std::unique_ptr��������ָ�룬����Ǳ�ڵ��ڴ�й©���⡣
Cazel::Application* Cazel::CreateApplication()
{
    return new Sandbox(); // ����������һ�� Sandbox ʵ��
}