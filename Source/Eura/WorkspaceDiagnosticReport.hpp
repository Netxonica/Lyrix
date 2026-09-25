// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_diagnostic_report
#define lyrix_header_guard_eura_workspace_diagnostic_report
#include "Eura/WorkspaceDocumentDiagnosticReport.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceDiagnosticReport final
    {
        std::vector<WorkspaceDocumentDiagnosticReport> items;
    };

    auto from_json(const nlohmann::json& object, WorkspaceDiagnosticReport&
    workspace_diagnostic_report) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceDiagnosticReport&
    workspace_diagnostic_report) noexcept -> void;
}

#endif
#endif