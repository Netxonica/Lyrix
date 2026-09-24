// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_diagnostic_report_kind
#define lyrix_header_guard_eura_document_diagnostic_report_kind
#include <string>

namespace Eura
{
    using DocumentDiagnosticReportKind = std::string;

    inline const DocumentDiagnosticReportKind Full = "full", Unchanged = "unchanged";
}

#endif
#endif