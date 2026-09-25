// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_document_diagnostic_report_partial_result
#define lyrix_header_guard_eura_document_diagnostic_report_partial_result
#include "Eura/FullDocumentDiagnosticReport.hpp"
#include "Eura/UnchangedDocumentDiagnosticReport.hpp"

namespace Eura
{
    struct [[nodiscard]] DocumentDiagnosticReportPartialResult final
    {
        std::unordered_map<std::string, std::variant<FullDocumentDiagnosticReport,
        UnchangedDocumentDiagnosticReport>> relatedDocuments;
    };

    auto from_json(const nlohmann::json& object, DocumentDiagnosticReportPartialResult&
    document_diagnostic_report_partial_result) noexcept -> void;

    auto to_json(nlohmann::json& object, const DocumentDiagnosticReportPartialResult&
    document_diagnostic_report_partial_result) noexcept -> void;
}

#endif
#endif