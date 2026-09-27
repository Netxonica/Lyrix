// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ApplyWorkspaceEditResult.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ApplyWorkspaceEditResult&
    apply_workspace_edit_result) noexcept -> void
    {
        apply_workspace_edit_result.applied = object.at("applied").get<bool>();
        if(object.contains("failureReason"))
            apply_workspace_edit_result.failureReason = object.at("failureReason").get<std::string>
            ();
        if(object.contains("failedChange"))
            apply_workspace_edit_result.failedChange = object.at("failedChange").get<std::uint32_t>
            ();
    }

    auto to_json(nlohmann::json& object, const ApplyWorkspaceEditResult&
    apply_workspace_edit_result) noexcept -> void
    {
        object["applied"] = apply_workspace_edit_result.applied;
        if(apply_workspace_edit_result.failureReason.has_value())
            object["failureReason"] = *apply_workspace_edit_result.failureReason;
        if(apply_workspace_edit_result.failedChange.has_value())
            object["failedChange"] = *apply_workspace_edit_result.failedChange;
    }
}

#endif