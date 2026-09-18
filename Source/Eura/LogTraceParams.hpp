// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_log_trace_params
#define lyrix_header_guard_eura_log_trace_params
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] LogTraceParams final
    {
        std::string message;

        std::optional<std::string> verbose;
    };

    auto from_json(const nlohmann::json& object, LogTraceParams& log_trace_params) noexcept -> void
    ;

    auto to_json(nlohmann::json& object, const LogTraceParams& log_trace_params) noexcept -> void;
}

#endif
#endif