// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_publish_diagnostics_client_capabilities
#define lyrix_header_guard_eura_publish_diagnostics_client_capabilities
#include "Eura/ClientDiagnosticsTagOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] PublishDiagnosticsClientCapabilities final
    {
        std::optional<bool> relatedInformation;

        std::optional<ClientDiagnosticsTagOptions> tagSupport;

        std::optional<bool> versionSupport, codeDescriptionSupport, dataSupport;
    };

    auto from_json(const nlohmann::json& object, PublishDiagnosticsClientCapabilities&
    publish_diagnostics_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const PublishDiagnosticsClientCapabilities&
    publish_diagnostics_client_capabilities) noexcept -> void;
}

#endif
#endif