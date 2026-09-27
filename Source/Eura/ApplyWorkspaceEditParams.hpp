// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_apply_workspace_edit_params
#define lyrix_header_guard_eura_apply_workspace_edit_params
#include "Eura/WorkspaceEdit.hpp"
#include "Eura/WorkspaceEditMetadata.hpp"

namespace Eura
{
    struct [[nodiscard]] ApplyWorkspaceEditParams final
    {
        std::optional<std::string> label;

        WorkspaceEdit edit;

        std::optional<WorkspaceEditMetadata> metadata;
    };

    auto from_json(const nlohmann::json& object, ApplyWorkspaceEditParams&
    apply_workspace_edit_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const ApplyWorkspaceEditParams&
    apply_workspace_edit_params) noexcept -> void;
}

#endif
#endif