// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_related_unchanged_document_diagnostic_report
#define lyrix_header_guard_eura_related_unchanged_document_diagnostic_report
#include "Eura/FullDocumentDiagnosticReport.hpp"
#include "Eura/UnchangedDocumentDiagnosticReport.hpp"

namespace Eura
{
    struct [[nodiscard]] RelatedUnchangedDocumentDiagnosticReport final :
    UnchangedDocumentDiagnosticReport
    {
        std::optional<std::unordered_map<std::string, std::variant<FullDocumentDiagnosticReport,
        UnchangedDocumentDiagnosticReport>>> relatedDocuments;
    };

    auto from_json(const nlohmann::json& object, RelatedUnchangedDocumentDiagnosticReport&
    related_unchanged_document_diagnostic_report) noexcept -> void;

    auto to_json(nlohmann::json& object, const RelatedUnchangedDocumentDiagnosticReport&
    related_unchanged_document_diagnostic_report) noexcept -> void;
}

#endif
#endif