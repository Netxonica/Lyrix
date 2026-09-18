// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LogTraceParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, LogTraceParams& log_trace_params) noexcept -> void
    {
        log_trace_params.message = object.at("message").get<std::string>();
        if(object.contains("verbose"))
            log_trace_params.verbose = object.at("verbose").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const LogTraceParams& log_trace_params) noexcept -> void
    {
        object["message"] = log_trace_params.message;
        if(log_trace_params.verbose.has_value())
            object["verbose"] = *log_trace_params.verbose;
    }
}

#endif