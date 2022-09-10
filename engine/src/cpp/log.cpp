#include "log.hpp"

namespace Engine {
    std::shared_ptr<spdlog::logger> Log::s_EngineLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init(){
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_EngineLogger = spdlog::stdout_color_mt("ENGINE");
        s_EngineLogger->set_level(spdlog::level::trace);

        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}
