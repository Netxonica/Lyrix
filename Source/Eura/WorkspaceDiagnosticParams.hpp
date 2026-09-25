// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_diagnostic_params
#define lyrix_header_guard_eura_workspace_diagnostic_params
#include "Eura/PreviousResultId.hpp"
#include "Eura/PartialResultParams.hpp"
#include "Eura/WorkDoneProgressParams.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceDiagnosticParams final : WorkDoneProgressParams,
    PartialResultParams
    {
        std::optional<std::string> identifier;

        std::vector<PreviousResultId> previousResultIds;
    };

    auto from_json(const nlohmann::json& object, WorkspaceDiagnosticParams&
    workspace_diagnostic_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceDiagnosticParams&
    workspace_diagnostic_params) noexcept -> void;
}

#endif
#endif