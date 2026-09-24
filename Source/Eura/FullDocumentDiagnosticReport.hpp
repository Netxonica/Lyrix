// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_full_document_diagnostic_report
#define lyrix_header_guard_eura_full_document_diagnostic_report
#include "Eura/Diagnostic.hpp"
#include "Eura/DocumentDiagnosticReportKind.hpp"

namespace Eura
{
    struct [[nodiscard]] FullDocumentDiagnosticReport
    {
        DocumentDiagnosticReportKind kind; // always Full

        std::optional<std::string> resultId;

        std::vector<Diagnostic> items;
    };

    auto from_json(const nlohmann::json& object, FullDocumentDiagnosticReport&
    full_document_diagnostic_report) noexcept -> void;

    auto to_json(nlohmann::json& object, const FullDocumentDiagnosticReport&
    full_document_diagnostic_report) noexcept -> void;
}

#endif
#endif