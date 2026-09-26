// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentRangeFormattingParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentRangeFormattingParams&
    document_range_formatting_params) noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(document_range_formatting_params));
        document_range_formatting_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        document_range_formatting_params.range = object.at("range").get<Range>();
        document_range_formatting_params.options = object.at("options").get<FormattingOptions>();
    }

    auto to_json(nlohmann::json& object, const DocumentRangeFormattingParams&
    document_range_formatting_params) noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(document_range_formatting_params
        ));
        object["textDocument"] = document_range_formatting_params.textDocument;
        object["range"] = document_range_formatting_params.range;
        object["options"] = document_range_formatting_params.options;
    }
}

#endif