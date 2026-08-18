// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceFolder.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceFolder& workspace_folder) noexcept ->
    void
    {
        workspace_folder.uri = object.at("uri").get<URI>();
        workspace_folder.name = object.at("name").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const WorkspaceFolder& workspace_folder) noexcept -> void
    {
        object["uri"] = workspace_folder.uri;
        object["name"] = workspace_folder.name;
    }
}

#endif