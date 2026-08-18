// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/VersionedTextDocumentIdentifier.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, VersionedTextDocumentIdentifier&
    versioned_text_document_identifier) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentIdentifier&>(versioned_text_document_identifier))
        ;
        versioned_text_document_identifier.version = object.at("version").get<std::int32_t>();
    }

    auto to_json(nlohmann::json& object, const VersionedTextDocumentIdentifier&
    versioned_text_document_identifier) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentIdentifier&>(
        versioned_text_document_identifier));
        object["version"] = versioned_text_document_identifier.version;
    }
}

#endif