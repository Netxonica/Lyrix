// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_diagnostic_report_partial_result
#define lyrix_header_guard_eura_workspace_diagnostic_report_partial_result
#include "Eura/WorkspaceDocumentDiagnosticReport.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceDiagnosticReportPartialResult final
    {
        std::vector<WorkspaceDocumentDiagnosticReport> items;
    };

    auto from_json(const nlohmann::json& object, WorkspaceDiagnosticReportPartialResult&
    workspace_diagnostic_report_partial_result) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceDiagnosticReportPartialResult&
    workspace_diagnostic_report_partial_result) noexcept -> void;
}

#endif
#endif