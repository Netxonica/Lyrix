// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RelatedFullDocumentDiagnosticReport.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RelatedFullDocumentDiagnosticReport&
    related_full_document_diagnostic_report) noexcept -> void
    {
        from_json(object, static_cast<FullDocumentDiagnosticReport&>(
        related_full_document_diagnostic_report));
        if(object.contains("relatedDocuments"))
        {
            related_full_document_diagnostic_report.relatedDocuments = std::unordered_map<std::
            string, std::variant<FullDocumentDiagnosticReport, UnchangedDocumentDiagnosticReport>>{
            };
            const nlohmann::json& relatedDocuments = object.at("relatedDocuments");
            for(const auto& [uri, document] : relatedDocuments.items())
            {
                const DocumentDiagnosticReportKind& kind = document.at("kind");
                if(kind == Full)
                    related_full_document_diagnostic_report.relatedDocuments->emplace(uri, document
                    .get<FullDocumentDiagnosticReport>());
                else
                    related_full_document_diagnostic_report.relatedDocuments->emplace(uri, document
                    .get<UnchangedDocumentDiagnosticReport>());
            }
        }
    }

    auto to_json(nlohmann::json& object, const RelatedFullDocumentDiagnosticReport&
    related_full_document_diagnostic_report) noexcept -> void
    {
        to_json(object, static_cast<const FullDocumentDiagnosticReport&>(
        related_full_document_diagnostic_report));
        if(related_full_document_diagnostic_report.relatedDocuments.has_value())
        {
            nlohmann::json relatedDocuments = nlohmann::json::object();
            for(const auto& [uri, document] : *related_full_document_diagnostic_report.
            relatedDocuments)
                std::visit([&relatedDocuments, &uri](auto&& document)
                {
                    relatedDocuments[uri] = document;
                }, document);
            object["relatedDocuments"] = relatedDocuments;
        }
    }
}

#endif