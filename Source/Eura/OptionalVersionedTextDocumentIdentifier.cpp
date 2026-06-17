// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/OptionalVersionedTextDocumentIdentifier.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, OptionalVersionedTextDocumentIdentifier&
    optional_versioned_text_document_identifier) noexcept -> void
    {
        Deserialize(object, static_cast<TextDocumentIdentifier&>(
        optional_versioned_text_document_identifier));
        const Json::Any& version = object.Retrieve("version");
        if(version.IsUinteger())
            optional_versioned_text_document_identifier.version = static_cast<Json::Integer>(
            version.As<Json::Uinteger>());
        else if(version.IsInteger())
            optional_versioned_text_document_identifier.version = version.As<Json::Integer>();
        else if(version.IsNull())
            optional_versioned_text_document_identifier.version = Json::Null{};
        else
            std::abort();
    }

    auto Serialize(Json::Object& object, const OptionalVersionedTextDocumentIdentifier&
    optional_versioned_text_document_identifier) noexcept -> void
    {
        Serialize(object, static_cast<const TextDocumentIdentifier&>(
        optional_versioned_text_document_identifier));
        std::visit([&object](auto&& version)
        {
            object.fields.emplace_back("version", version);
        }, optional_versioned_text_document_identifier.version);
    }
}

#endif