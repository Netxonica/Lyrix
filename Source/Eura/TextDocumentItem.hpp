// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_item
#define lyrix_header_guard_eura_text_document_item
#include "Eura/Any.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentItem final
    {
        DocumentUri uri;

        Json::String languageId;

        Json::Integer version;

        Json::String text;
    };

    auto Deserialize(const Json::Object& object, TextDocumentItem& text_document_item) noexcept ->
    void;

    auto Serialize(Json::Object& object, const TextDocumentItem& text_document_item) noexcept ->
    void;
}

#endif
#endif