// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_change_workspace_folders_params
#define lyrix_header_guard_eura_did_change_workspace_folders_params
#include "Eura/WorkspaceFoldersChangeEvent.hpp"

namespace Eura
{
    struct [[nodiscard]] DidChangeWorkspaceFoldersParams final
    {
        WorkspaceFoldersChangeEvent event;
    };

    auto from_json(const nlohmann::json& object, DidChangeWorkspaceFoldersParams&
    did_change_workspace_folders_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidChangeWorkspaceFoldersParams&
    did_change_workspace_folders_params) noexcept -> void;
}

#endif
#endif