// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DiagnosticServerCancellationData.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DiagnosticServerCancellationData&
    diagnostic_server_cancellation_data) noexcept -> void
    {
        diagnostic_server_cancellation_data.retriggerRequest = object.at("retriggerRequest").get<
        bool>();
    }

    auto to_json(nlohmann::json& object, const DiagnosticServerCancellationData&
    diagnostic_server_cancellation_data) noexcept -> void
    {
        object["retriggerRequest"] = diagnostic_server_cancellation_data.retriggerRequest;
    }
}

#endif