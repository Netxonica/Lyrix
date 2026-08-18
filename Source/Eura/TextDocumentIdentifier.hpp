// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_identifier
#define lyrix_header_guard_eura_text_document_identifier
#include "Eura/Json.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentIdentifier final
    {
        DocumentUri uri;
    };

    auto from_json(const nlohmann::json& object, TextDocumentIdentifier& text_document_identifier)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const TextDocumentIdentifier& text_document_identifier)
    noexcept -> void;
}

#endif
#endif