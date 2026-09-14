// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_options
#define lyrix_header_guard_eura_workspace_options
#include "Eura/FileOperationOptions.hpp"
#include "Eura/WorkspaceFoldersServerCapabilities.hpp"
#include "Eura/TextDocumentContentRegistrationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceOptions final
    {
        std::optional<WorkspaceFoldersServerCapabilities> workspaceFolders;

        std::optional<FileOperationOptions> fileOperations;

        std::optional<std::variant<TextDocumentContentOptions,
        TextDocumentContentRegistrationOptions>> textDocumentContent;
    };

    auto from_json(const nlohmann::json& object, WorkspaceOptions& workspace_options) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const WorkspaceOptions& workspace_options) noexcept ->
    void;
}

#endif
#endif