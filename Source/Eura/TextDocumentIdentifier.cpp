// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentIdentifier.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentIdentifier& text_document_identifier)
    noexcept -> void
    {
        text_document_identifier.uri = object.at("uri").get<DocumentUri>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentIdentifier& text_document_identifier)
    noexcept -> void
    {
        object["uri"] = text_document_identifier.uri;
    }
}

#endif