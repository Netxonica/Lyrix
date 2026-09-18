// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ExecutionSummary.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ExecutionSummary& execution_summary) noexcept ->
    void
    {
        execution_summary.executionOrder = object.at("executionOrder").get<std::uint32_t>();
        if(object.contains("success"))
            execution_summary.success = object.at("success").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ExecutionSummary& execution_summary) noexcept ->
    void
    {
        object["executionOrder"] = execution_summary.executionOrder;
        if(execution_summary.success.has_value())
            object["success"] = *execution_summary.success;
    }
}

#endif