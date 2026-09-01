// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_capabilities
#define lyrix_header_guard_eura_client_capabilities
#include "Eura/WindowClientCapabilities.hpp"
#include "Eura/GeneralClientCapabilities.hpp"
#include "Eura/WorkspaceClientCapabilities.hpp"
#include "Eura/TextDocumentClientCapabilities.hpp"
#include "Eura/NotebookDocumentClientCapabilities.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientCapabilities final
    {
        std::optional<WorkspaceClientCapabilities> workspace;

        std::optional<TextDocumentClientCapabilities> textDocument;

        std::optional<NotebookDocumentClientCapabilities> notebookDocument;

        std::optional<WindowClientCapabilities> window;

        std::optional<GeneralClientCapabilities> general;

        std::optional<nlohmann::json> experimental;
    };

    auto from_json(const nlohmann::json& object, ClientCapabilities& client_capabilities) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const ClientCapabilities& client_capabilities) noexcept ->
    void;
}

#endif
#endif