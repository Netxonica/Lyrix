// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SetTraceParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SetTraceParams& set_trace_params) noexcept -> void
    {
        set_trace_params.value = object.at("value").get<TraceValue>();
    }

    auto to_json(nlohmann::json& object, const SetTraceParams& set_trace_params) noexcept -> void
    {
        object["value"] = set_trace_params.value;
    }
}

#endif