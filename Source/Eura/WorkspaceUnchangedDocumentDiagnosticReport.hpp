// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_unchanged_document_diagnostic_report
#define lyrix_header_guard_eura_workspace_unchanged_document_diagnostic_report
#include "Eura/DocumentUri.hpp"
#include "Eura/UnchangedDocumentDiagnosticReport.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceUnchangedDocumentDiagnosticReport final :
    UnchangedDocumentDiagnosticReport
    {
        DocumentUri uri;

        std::variant<std::int32_t, std::nullptr_t> version;
    };

    auto from_json(const nlohmann::json& object, WorkspaceUnchangedDocumentDiagnosticReport&
    workspace_unchanged_document_diagnostic_report) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceUnchangedDocumentDiagnosticReport&
    workspace_unchanged_document_diagnostic_report) noexcept -> void;
}

#endif
#endif