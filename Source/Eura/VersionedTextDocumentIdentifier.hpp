// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_versioned_text_document_identifier
#define lyrix_header_guard_eura_versioned_text_document_identifier
#include "Eura/TextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] VersionedTextDocumentIdentifier final : TextDocumentIdentifier
    {
        std::int32_t version;
    };

    auto from_json(const nlohmann::json& object, VersionedTextDocumentIdentifier&
    versioned_text_document_identifier) noexcept -> void;

    auto to_json(nlohmann::json& object, const VersionedTextDocumentIdentifier&
    versioned_text_document_identifier) noexcept -> void;
}

#endif
#endif