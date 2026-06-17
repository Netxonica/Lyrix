// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_versioned_text_document_identifier
#define lyrix_header_guard_eura_versioned_text_document_identifier
#include "Eura/TextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] VersionedTextDocumentIdentifier final : public TextDocumentIdentifier
    {
        Json::Integer version;
    };

    auto Deserialize(const Json::Object& object, VersionedTextDocumentIdentifier&
    versioned_text_document_identifier) noexcept -> void;

    auto Serialize(Json::Object& object, const VersionedTextDocumentIdentifier&
    versioned_text_document_identifier) noexcept -> void;
}

#endif
#endif