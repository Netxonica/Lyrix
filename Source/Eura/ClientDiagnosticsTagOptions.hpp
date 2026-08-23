// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_diagnostics_tag_options
#define lyrix_header_guard_eura_client_diagnostics_tag_options
#include "Eura/Json.hpp"
#include "Eura/DiagnosticTag.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientDiagnosticsTagOptions final
    {
        std::vector<DiagnosticTag> valueSet;
    };

    auto from_json(const nlohmann::json& object, ClientDiagnosticsTagOptions&
    client_diagnostics_tag_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientDiagnosticsTagOptions&
    client_diagnostics_tag_options) noexcept -> void;
}

#endif
#endif