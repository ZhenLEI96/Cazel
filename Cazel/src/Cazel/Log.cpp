#include "Log.h" // ������־ϵͳ������

namespace Cazel { // ʹ�������ռ����������ͻ

    // ���徲̬��Ա���� s_CoreLogger �� s_ClientLogger
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    // ��ʼ����־ϵͳ
    void Log::Init()
    {
        // ����ȫ����־��ʽ
        // �Ż����飺���������û�ͨ�������ļ�������Զ�����־��ʽ��
        spdlog::set_pattern("%^[%T] %n: %v%$");

        // ��������ģ����־��������Ϊ "HAZEL"
        s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
        s_CoreLogger->set_level(spdlog::level::trace); // ������־����Ϊ trace

        // �����ͻ���ģ����־��������Ϊ "APP"
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace); // ������־����Ϊ trace

        // �Ż����飺
        // 1. ��Ӷ��ļ���־��֧�֣����罫��־������ļ��С�
        // ʾ����
        // auto file_logger = spdlog::basic_logger_mt("file_logger", "logs/log.txt");
        // s_CoreLogger->sinks().push_back(file_logger->sinks().front());

        // 2. �ڷ����汾�ж�̬������־����������� TRACE �� INFO��
        // ʾ����
        // #ifdef NDEBUG
        // s_CoreLogger->set_level(spdlog::level::warn);
        // s_ClientLogger->set_level(spdlog::level::warn);
        // #endif
    }

} // namespace Cazel