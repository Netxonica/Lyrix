// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentDiagnosticReportPartialResult.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentDiagnosticReportPartialResult&
    document_diagnostic_report_partial_result) noexcept -> void
    {
        const nlohmann::json& relatedDocuments = object.at("relatedDocuments");
        for(const auto& [uri, document] : relatedDocuments.items())
        {
            const DocumentDiagnosticReportKind& kind = document.at("kind");
            if(kind == Full)
                document_diagnostic_report_partial_result.relatedDocuments.emplace(uri, document.
                get<FullDocumentDiagnosticReport>());
            else
                document_diagnostic_report_partial_result.relatedDocuments.emplace(uri, document.
                get<UnchangedDocumentDiagnosticReport>());
        }
    }

    auto to_json(nlohmann::json& object, const DocumentDiagnosticReportPartialResult&
    document_diagnostic_report_partial_result) noexcept -> void
    {
        nlohmann::json relatedDocuments = nlohmann::json::object();
        for(const auto& [uri, document] : document_diagnostic_report_partial_result.
        relatedDocuments)
            std::visit([&relatedDocuments, &uri](auto&& document)
            {
                relatedDocuments[uri] = document;
            }, document);
        object["relatedDocuments"] = relatedDocuments;
    }
}

#endif