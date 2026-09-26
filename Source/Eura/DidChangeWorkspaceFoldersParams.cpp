// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeWorkspaceFoldersParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidChangeWorkspaceFoldersParams&
    did_change_workspace_folders_params) noexcept -> void
    {
        did_change_workspace_folders_params.event = object.at("event").get<
        WorkspaceFoldersChangeEvent>();
    }

    auto to_json(nlohmann::json& object, const DidChangeWorkspaceFoldersParams&
    did_change_workspace_folders_params) noexcept -> void
    {
        object["event"] = did_change_workspace_folders_params.event;
    }
}

#endif