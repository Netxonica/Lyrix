// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceFoldersChangeEvent.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceFoldersChangeEvent&
    workspace_folders_change_event) noexcept -> void
    {
        const nlohmann::json& added = object.at("added");
        for(const nlohmann::json& adde : added)
            workspace_folders_change_event.added.emplace_back(adde.get<WorkspaceFolder>());
        const nlohmann::json& removed = object.at("removed");
        for(const nlohmann::json& remove : removed)
            workspace_folders_change_event.removed.emplace_back(remove.get<WorkspaceFolder>());
    }

    auto to_json(nlohmann::json& object, const WorkspaceFoldersChangeEvent&
    workspace_folders_change_event) noexcept -> void
    {
        nlohmann::json added = nlohmann::json::array();
        for(const WorkspaceFolder& adde : workspace_folders_change_event.added)
            added.emplace_back(adde);
        object["added"] = added;
        nlohmann::json removed = nlohmann::json::array();
        for(const WorkspaceFolder& remove : workspace_folders_change_event.removed)
            removed.emplace_back(remove);
        object["removed"] = removed;
    }
}

#endif