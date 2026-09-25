// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_diagnostic_server_cancellation_data
#define lyrix_header_guard_eura_diagnostic_server_cancellation_data
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] DiagnosticServerCancellationData final
    {
        bool retriggerRequest;
    };

    auto from_json(const nlohmann::json& object, DiagnosticServerCancellationData&
    diagnostic_server_cancellation_data) noexcept -> void;

    auto to_json(nlohmann::json& object, const DiagnosticServerCancellationData&
    diagnostic_server_cancellation_data) noexcept -> void;
}

#endif
#endif