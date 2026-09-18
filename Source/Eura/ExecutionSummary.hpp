// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_execution_summary
#define lyrix_header_guard_eura_execution_summary
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ExecutionSummary final
    {
        std::uint32_t executionOrder;

        std::optional<bool> success;
    };

    auto from_json(const nlohmann::json& object, ExecutionSummary& execution_summary) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const ExecutionSummary& execution_summary) noexcept ->
    void;
}

#endif
#endif