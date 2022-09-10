#pragma once 

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Engine {
    class Log {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_EngineLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// MACROS FOR LOGGING
// ENGINE LOGGING
#define ENGINE_TRACE(...)    ::Engine::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...)     ::Engine::Log::GetEngineLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...)     ::Engine::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...)    ::Engine::Log::GetEngineLogger()->error(__VA_ARGS__)
#define ENGINE_FATAL(...)    ::Engine::Log::GetEngineLogger()->critical(__VA_ARGS__)
// APPLICATION LOGGING
#define APP_TRACE(...)       ::Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define APP_INFO(...)        ::Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define APP_WARN(...)        ::Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define APP_ERROR(...)       ::Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define APP_FATAL(...)       ::Engine::Log::GetClientLogger()->critical(__VA_ARGS__)

