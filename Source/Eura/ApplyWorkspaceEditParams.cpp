// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ApplyWorkspaceEditParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ApplyWorkspaceEditParams&
    apply_workspace_edit_params) noexcept -> void
    {
        if(object.contains("label"))
            apply_workspace_edit_params.label = object.at("label").get<std::string>();
        apply_workspace_edit_params.edit = object.at("edit").get<WorkspaceEdit>();
        if(object.contains("metadata"))
            apply_workspace_edit_params.metadata = object.at("metadata").get<WorkspaceEditMetadata>
            ();
    }

    auto to_json(nlohmann::json& object, const ApplyWorkspaceEditParams&
    apply_workspace_edit_params) noexcept -> void
    {
        if(apply_workspace_edit_params.label.has_value())
            object["label"] = *apply_workspace_edit_params.label;
        object["edit"] = apply_workspace_edit_params.edit;
        if(apply_workspace_edit_params.metadata.has_value())
            object["metadata"] = *apply_workspace_edit_params.metadata;
    }
}

#endif