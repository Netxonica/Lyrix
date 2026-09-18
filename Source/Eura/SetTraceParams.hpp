// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_set_trace_params
#define lyrix_header_guard_eura_set_trace_params
#include "Eura/Json.hpp"
#include "Eura/TraceValue.hpp"

namespace Eura
{
    struct [[nodiscard]] SetTraceParams final
    {
        TraceValue value;
    };

    auto from_json(const nlohmann::json& object, SetTraceParams& set_trace_params) noexcept -> void
    ;

    auto to_json(nlohmann::json& object, const SetTraceParams& set_trace_params) noexcept -> void;
}

#endif
#endif