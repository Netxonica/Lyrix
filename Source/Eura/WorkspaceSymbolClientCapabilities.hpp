// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_symbol_client_capabilities
#define lyrix_header_guard_eura_workspace_symbol_client_capabilities
#include "Eura/ClientSymbolTagOptions.hpp"
#include "Eura/ClientSymbolKindOptions.hpp"
#include "Eura/ClientSymbolResolveOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceSymbolClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;

        std::optional<ClientSymbolKindOptions> symbolKind;

        std::optional<ClientSymbolTagOptions> tagSupport;

        std::optional<ClientSymbolResolveOptions> resolveSupport;
    };

    auto from_json(const nlohmann::json& object, WorkspaceSymbolClientCapabilities&
    workspace_symbol_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceSymbolClientCapabilities&
    workspace_symbol_client_capabilities) noexcept -> void;
}

#endif
#endif