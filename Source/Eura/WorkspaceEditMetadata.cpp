// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceEditMetadata.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceEditMetadata& workspace_edit_metadata)
    noexcept -> void
    {
        if(object.contains("isRefactoring"))
            workspace_edit_metadata.isRefactoring = object.at("isRefactoring").get<bool>();
    }

    auto to_json(nlohmann::json& object, const WorkspaceEditMetadata& workspace_edit_metadata)
    noexcept -> void
    {
        if(workspace_edit_metadata.isRefactoring.has_value())
            object["isRefactoring"] = *workspace_edit_metadata.isRefactoring;
    }
}

#endif