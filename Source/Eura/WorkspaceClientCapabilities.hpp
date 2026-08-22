// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_client_capabilities
#define lyrix_header_guard_eura_workspace_client_capabilities
#include "Eura/WorkspaceEditClientCapabilities.hpp"
#include "Eura/FileOperationClientCapabilities.hpp"
#include "Eura/ExecuteCommandClientCapabilities.hpp"
#include "Eura/WorkspaceSymbolClientCapabilities.hpp"
#include "Eura/CodeLensWorkspaceClientCapabilities.hpp"
#include "Eura/InlayHintWorkspaceClientCapabilities.hpp"
#include "Eura/DiagnosticWorkspaceClientCapabilities.hpp"
#include "Eura/TextDocumentContentClientCapabilities.hpp"
#include "Eura/InlineValueWorkspaceClientCapabilities.hpp"
#include "Eura/DidChangeWatchedFilesClientCapabilities.hpp"
#include "Eura/FoldingRangeWorkspaceClientCapabilities.hpp"
#include "Eura/DidChangeConfigurationClientCapabilities.hpp"
#include "Eura/SemanticTokensWorkspaceClientCapabilities.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceClientCapabilities final
    {
        std::optional<bool> applyEdit;

        std::optional<WorkspaceEditClientCapabilities> workspaceEdit;

        std::optional<DidChangeConfigurationClientCapabilities> didChangeConfiguration;

        std::optional<DidChangeWatchedFilesClientCapabilities> didChangeWatchedFiles;

        std::optional<WorkspaceSymbolClientCapabilities> symbol;

        std::optional<ExecuteCommandClientCapabilities> executeCommand;

        std::optional<bool> workspaceFolders, configuration;

        std::optional<SemanticTokensWorkspaceClientCapabilities> semanticTokens;

        std::optional<CodeLensWorkspaceClientCapabilities> codeLens;

        std::optional<FileOperationClientCapabilities> fileOperations;

        std::optional<InlineValueWorkspaceClientCapabilities> inlineValue;

        std::optional<InlayHintWorkspaceClientCapabilities> inlayHint;

        std::optional<DiagnosticWorkspaceClientCapabilities> diagnostics;

        std::optional<FoldingRangeWorkspaceClientCapabilities> foldingRange;

        std::optional<TextDocumentContentClientCapabilities> textDocumentContent;
    };

    auto from_json(const nlohmann::json& object, WorkspaceClientCapabilities&
    workspace_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceClientCapabilities&
    workspace_client_capabilities) noexcept -> void;
}

#endif
#endif