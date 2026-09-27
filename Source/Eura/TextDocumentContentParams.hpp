// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_content_params
#define lyrix_header_guard_eura_text_document_content_params
#include "Eura/Json.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentContentParams final
    {
        DocumentUri uri;
    };

    auto from_json(const nlohmann::json& object, TextDocumentContentParams&
    text_document_content_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentContentParams&
    text_document_content_params) noexcept -> void;
}

#endif
#endif