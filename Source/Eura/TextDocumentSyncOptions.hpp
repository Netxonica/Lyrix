// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_sync_options
#define lyrix_header_guard_eura_text_document_sync_options
#include "Eura/Json.hpp"
#include "Eura/TextDocumentSyncKind.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentSyncOptions final
    {
        std::optional<bool> openClose;

        std::optional<TextDocumentSyncKind> change;
    };

    auto from_json(const nlohmann::json& object, TextDocumentSyncOptions&
    text_document_sync_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentSyncOptions& text_document_sync_options)
    noexcept -> void;
}

#endif
#endif