// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentDiagnosticParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentDiagnosticParams&
    document_diagnostic_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(document_diagnostic_params));
        from_json(object, static_cast<PartialResultParams&>(document_diagnostic_params));
        document_diagnostic_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        if(object.contains("identifier"))
            document_diagnostic_params.identifier = object.at("identifier").get<std::string>();
        if(object.contains("previousResultId"))
            document_diagnostic_params.previousResultId = object.at("previousResultId").get<std::
            string>();
    }

    auto to_json(nlohmann::json& object, const DocumentDiagnosticParams& document_diagnostic_params
    ) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(document_diagnostic_params));
        to_json(object, static_cast<const PartialResultParams&>(document_diagnostic_params));
        object["textDocument"] = document_diagnostic_params.textDocument;
        if(document_diagnostic_params.identifier.has_value())
            object["identifier"] = *document_diagnostic_params.identifier;
        if(document_diagnostic_params.previousResultId.has_value())
            object["previousResultId"] = *document_diagnostic_params.previousResultId;
    }
}

#endif