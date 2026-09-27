// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_apply_workspace_edit_result
#define lyrix_header_guard_eura_apply_workspace_edit_result
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ApplyWorkspaceEditResult final
    {
        bool applied;

        std::optional<std::string> failureReason;

        std::optional<std::uint32_t> failedChange;
    };

    auto from_json(const nlohmann::json& object, ApplyWorkspaceEditResult&
    apply_workspace_edit_result) noexcept -> void;

    auto to_json(nlohmann::json& object, const ApplyWorkspaceEditResult&
    apply_workspace_edit_result) noexcept -> void;
}

#endif
#endif