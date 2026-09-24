// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FullDocumentDiagnosticReport.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FullDocumentDiagnosticReport&
    full_document_diagnostic_report) noexcept -> void
    {
        full_document_diagnostic_report.kind = object.at("kind").get<DocumentDiagnosticReportKind>(
        );
        if(object.contains("resultId"))
            full_document_diagnostic_report.resultId = object.at("resultId").get<std::string>();
        const nlohmann::json& items = object.at("items");
        for(const nlohmann::json& item : items)
            full_document_diagnostic_report.items.emplace_back(item.get<Diagnostic>());
    }

    auto to_json(nlohmann::json& object, const FullDocumentDiagnosticReport&
    full_document_diagnostic_report) noexcept -> void
    {
        object["kind"] = full_document_diagnostic_report.kind;
        if(full_document_diagnostic_report.resultId.has_value())
            object["resultId"] = *full_document_diagnostic_report.resultId;
        nlohmann::json items = nlohmann::json::array();
        for(const Diagnostic& item : full_document_diagnostic_report.items)
            items.emplace_back(item);
        object["items"] = items;
    }
}

#endif