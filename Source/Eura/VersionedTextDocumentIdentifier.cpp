// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/VersionedTextDocumentIdentifier.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, VersionedTextDocumentIdentifier&
    versioned_text_document_identifier) noexcept -> void
    {
        Deserialize(object, static_cast<TextDocumentIdentifier&>(versioned_text_document_identifier
        ));
        const Json::Any& version = object.Retrieve("version");
        if(version.IsUinteger())
            versioned_text_document_identifier.version = static_cast<Json::Integer>(version.As<Json
            ::Uinteger>());
        else if(version.IsInteger())
            versioned_text_document_identifier.version = version.As<Json::Integer>();
        else
            std::abort();
    }

    auto Serialize(Json::Object& object, const VersionedTextDocumentIdentifier&
    versioned_text_document_identifier) noexcept -> void
    {
        Serialize(object, static_cast<const TextDocumentIdentifier&>(
        versioned_text_document_identifier));
        object.fields.emplace_back("version", versioned_text_document_identifier.version);
    }
}

#endif