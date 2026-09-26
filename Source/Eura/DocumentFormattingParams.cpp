// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentFormattingParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentFormattingParams&
    document_formatting_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(document_formatting_params));
        document_formatting_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        document_formatting_params.options = object.at("options").get<FormattingOptions>();
    }

    auto to_json(nlohmann::json& object, const DocumentFormattingParams& document_formatting_params
    ) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(document_formatting_params));
        object["textDocument"] = document_formatting_params.textDocument;
        object["options"] = document_formatting_params.options;
    }
}

#endif