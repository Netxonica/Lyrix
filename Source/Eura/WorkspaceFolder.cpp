// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceFolder.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, WorkspaceFolder& workspace_folder) noexcept ->
    void
    {
        workspace_folder.uri = object.Retrieve("uri").As<URI>();
        workspace_folder.name = object.Retrieve("name").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const WorkspaceFolder& workspace_folder) noexcept -> void
    {
        object.fields.emplace_back("uri", workspace_folder.uri);
        object.fields.emplace_back("name", workspace_folder.name);
    }
}

#endif