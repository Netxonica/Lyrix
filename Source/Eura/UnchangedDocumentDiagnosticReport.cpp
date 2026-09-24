// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/UnchangedDocumentDiagnosticReport.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, UnchangedDocumentDiagnosticReport&
    unchanged_document_diagnostic_report) noexcept -> void
    {
        unchanged_document_diagnostic_report.kind = object.at("kind").get<
        DocumentDiagnosticReportKind>();
        unchanged_document_diagnostic_report.resultId = object.at("resultId").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const UnchangedDocumentDiagnosticReport&
    unchanged_document_diagnostic_report) noexcept -> void
    {
        object["kind"] = unchanged_document_diagnostic_report.kind;
        object["resultId"] = unchanged_document_diagnostic_report.resultId;
    }
}

#endif