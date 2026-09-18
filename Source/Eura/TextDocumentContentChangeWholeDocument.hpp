// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_content_change_whole_document
#define lyrix_header_guard_eura_text_document_content_change_whole_document
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentContentChangeWholeDocument final
    {
        std::string text;
    };

    auto from_json(const nlohmann::json& object, TextDocumentContentChangeWholeDocument&
    text_document_content_change_whole_document) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentContentChangeWholeDocument&
    text_document_content_change_whole_document) noexcept -> void;
}

#endif
#endif