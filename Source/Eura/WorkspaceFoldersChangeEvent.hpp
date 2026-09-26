// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_folders_change_event
#define lyrix_header_guard_eura_workspace_folders_change_event
#include "Eura/WorkspaceFolder.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceFoldersChangeEvent final
    {
        std::vector<WorkspaceFolder> added, removed;
    };

    auto from_json(const nlohmann::json& object, WorkspaceFoldersChangeEvent&
    workspace_folders_change_event) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceFoldersChangeEvent&
    workspace_folders_change_event) noexcept -> void;
}

#endif
#endif