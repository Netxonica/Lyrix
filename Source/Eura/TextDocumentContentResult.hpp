// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_content_result
#define lyrix_header_guard_eura_text_document_content_result
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentContentResult final
    {
        std::string text;
    };

    auto from_json(const nlohmann::json& object, TextDocumentContentResult&
    text_document_content_result) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentContentResult&
    text_document_content_result) noexcept -> void;
}

#endif
#endif