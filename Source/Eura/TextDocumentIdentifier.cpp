// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentIdentifier.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, TextDocumentIdentifier& text_document_identifier)
    noexcept -> void
    {
        text_document_identifier.uri = object.Retrieve("uri").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const TextDocumentIdentifier& text_document_identifier)
    noexcept -> void
    {
        object.fields.emplace_back("uri", text_document_identifier.uri);
    }
}

#endif