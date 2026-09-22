// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentLinkParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentLinkParams& document_link_params) noexcept
    -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(document_link_params));
        from_json(object, static_cast<PartialResultParams&>(document_link_params));
        document_link_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>()
        ;
    }

    auto to_json(nlohmann::json& object, const DocumentLinkParams& document_link_params) noexcept
    -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(document_link_params));
        to_json(object, static_cast<const PartialResultParams&>(document_link_params));
        object["textDocument"] = document_link_params.textDocument;
    }
}

#endif