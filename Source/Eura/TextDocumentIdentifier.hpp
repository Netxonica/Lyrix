// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_identifier
#define lyrix_header_guard_eura_text_document_identifier
#include "Eura/Any.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentIdentifier
    {
        DocumentUri uri;
    };

    auto Deserialize(const Json::Object& object, TextDocumentIdentifier& text_document_identifier)
    noexcept -> void;

    auto Serialize(Json::Object& object, const TextDocumentIdentifier& text_document_identifier)
    noexcept -> void;
}

#endif
#endif