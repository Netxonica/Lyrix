// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_content_refresh_params
#define lyrix_header_guard_eura_text_document_content_refresh_params
#include "Eura/Json.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentContentRefreshParams final
    {
        DocumentUri uri;
    };

    auto from_json(const nlohmann::json& object, TextDocumentContentRefreshParams&
    text_document_content_refresh_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentContentRefreshParams&
    text_document_content_refresh_params) noexcept -> void;
}

#endif
#endif