// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_workspace_document_diagnostic_report
#define lyrix_header_guard_eura_workspace_document_diagnostic_report
#include "Eura/WorkspaceFullDocumentDiagnosticReport.hpp"
#include "Eura/WorkspaceUnchangedDocumentDiagnosticReport.hpp"

namespace Eura
{
    using WorkspaceDocumentDiagnosticReport = std::variant<WorkspaceFullDocumentDiagnosticReport,
    WorkspaceUnchangedDocumentDiagnosticReport>;
}

#endif
#endif