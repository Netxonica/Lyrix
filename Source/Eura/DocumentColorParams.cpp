// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentColorParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentColorParams& document_color_params)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(document_color_params));
        from_json(object, static_cast<PartialResultParams&>(document_color_params));
        document_color_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>(
        );
    }

    auto to_json(nlohmann::json& object, const DocumentColorParams& document_color_params) noexcept
    -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(document_color_params));
        to_json(object, static_cast<const PartialResultParams&>(document_color_params));
        object["textDocument"] = document_color_params.textDocument;
    }
}

#endif