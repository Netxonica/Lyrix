// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_content_options
#define lyrix_header_guard_eura_text_document_content_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentContentOptions
    {
        std::vector<std::string> schemes;
    };

    auto from_json(const nlohmann::json& object, TextDocumentContentOptions&
    text_document_content_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentContentOptions&
    text_document_content_options) noexcept -> void;
}

#endif
#endif