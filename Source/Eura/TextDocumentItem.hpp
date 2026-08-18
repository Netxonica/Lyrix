// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_item
#define lyrix_header_guard_eura_text_document_item
#include "Eura/Json.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentItem final
    {
        DocumentUri uri;
        
        std::string languageId;

        std::int32_t version;

        std::string text;
    };

    auto from_json(const nlohmann::json& object, TextDocumentItem& text_document_item) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const TextDocumentItem& text_document_item) noexcept ->
    void;
}

#endif
#endif