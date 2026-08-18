// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/OptionalVersionedTextDocumentIdentifier.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, OptionalVersionedTextDocumentIdentifier&
    optional_versioned_text_document_identifier) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentIdentifier&>(
        optional_versioned_text_document_identifier));
        const nlohmann::json& version = object.at("version");
        if(version.is_number_integer())
            optional_versioned_text_document_identifier.version = version.get<std::int32_t>();
        else
            optional_versioned_text_document_identifier.version = nullptr;
    }

    auto to_json(nlohmann::json& object, const OptionalVersionedTextDocumentIdentifier&
    optional_versioned_text_document_identifier) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentIdentifier&>(
        optional_versioned_text_document_identifier));
        std::visit([&object](auto&& version)
        {
            object["version"] = version;
        }, optional_versioned_text_document_identifier.version);
    }
}

#endif