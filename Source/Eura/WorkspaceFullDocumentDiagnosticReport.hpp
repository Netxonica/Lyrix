// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_full_document_diagnostic_report
#define lyrix_header_guard_eura_workspace_full_document_diagnostic_report
#include "Eura/FullDocumentDiagnosticReport.hpp"

namespace Eura
{
    struct [[nodiscard]] WorkspaceFullDocumentDiagnosticReport final : FullDocumentDiagnosticReport
    {
        DocumentUri uri;

        std::variant<std::int32_t, std::nullptr_t> version;
    };

    auto from_json(const nlohmann::json& object, WorkspaceFullDocumentDiagnosticReport&
    workspace_full_document_diagnostic_report) noexcept -> void;

    auto to_json(nlohmann::json& object, const WorkspaceFullDocumentDiagnosticReport&
    workspace_full_document_diagnostic_report) noexcept -> void;
}

#endif
#endif