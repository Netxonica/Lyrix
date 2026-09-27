// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_edit_metadata
#define lyrix_header_guard_eura_workspace_edit_metadata
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceEditMetadata final
    {
        std::optional<bool> isRefactoring;
    };

    auto from_json(const nlohmann::json& object, WorkspaceEditMetadata& workspace_edit_metadata)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceEditMetadata& workspace_edit_metadata)
    noexcept -> void;
}

#endif
#endif