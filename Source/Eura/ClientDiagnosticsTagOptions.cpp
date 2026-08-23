// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientDiagnosticsTagOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientDiagnosticsTagOptions&
    client_diagnostics_tag_options) noexcept -> void
    {
        const nlohmann::json& valueSet = object.at("valueSet");
        for(const nlohmann::json& value : valueSet)
            client_diagnostics_tag_options.valueSet.emplace_back(static_cast<DiagnosticTag>(value.
            get<std::uint8_t>()));
    }

    auto to_json(nlohmann::json& object, const ClientDiagnosticsTagOptions&
    client_diagnostics_tag_options) noexcept -> void
    {
        nlohmann::json valueSet = nlohmann::json::array();
        for(const DiagnosticTag value : client_diagnostics_tag_options.valueSet)
            valueSet.emplace_back(static_cast<std::uint8_t>(value));
        object["valueSet"] = valueSet;
    }
}

#endif