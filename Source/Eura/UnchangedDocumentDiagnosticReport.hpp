// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_unchanged_document_diagnostic_report
#define lyrix_header_guard_eura_unchanged_document_diagnostic_report
#include "Eura/Json.hpp"
#include "Eura/DocumentDiagnosticReportKind.hpp"

namespace Eura
{
    struct [[nodiscard]] UnchangedDocumentDiagnosticReport final
    {
        DocumentDiagnosticReportKind kind; // always Unchanged

        std::string resultId;
    };

    auto from_json(const nlohmann::json& object, UnchangedDocumentDiagnosticReport&
    unchanged_document_diagnostic_report) noexcept -> void;

    auto to_json(nlohmann::json& object, const UnchangedDocumentDiagnosticReport&
    unchanged_document_diagnostic_report) noexcept -> void;
}

#endif
#endif