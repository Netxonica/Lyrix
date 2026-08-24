// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_diagnostic_client_capabilities
#define lyrix_header_guard_eura_diagnostic_client_capabilities
#include "Eura/ClientDiagnosticsTagOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] DiagnosticClientCapabilities final
    {
        std::optional<bool> dynamicRegistration, relatedDocumentSupport, relatedInformation;

        std::optional<ClientDiagnosticsTagOptions> tagSupport;

        std::optional<bool> codeDescriptionSupport, markupMessageSupport, dataSupport;
    };

    auto from_json(const nlohmann::json& object, DiagnosticClientCapabilities&
    diagnostic_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const DiagnosticClientCapabilities&
    diagnostic_client_capabilities) noexcept -> void;
}

#endif
#endif