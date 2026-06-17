// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_optional_versioned_text_document_identifier
#define lyrix_header_guard_eura_optional_versioned_text_document_identifier
#include "Eura/TextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] OptionalVersionedTextDocumentIdentifier final : public
    TextDocumentIdentifier
    {
        std::variant<Json::Integer, Json::Null> version;
    };

    auto Deserialize(const Json::Object& object, OptionalVersionedTextDocumentIdentifier&
    optional_versioned_text_document_identifier) noexcept -> void;

    auto Serialize(Json::Object& object, const OptionalVersionedTextDocumentIdentifier&
    optional_versioned_text_document_identifier) noexcept -> void;
}

#endif
#endif