// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentItem.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, TextDocumentItem& text_document_item) noexcept ->
    void
    {
        text_document_item.uri = object.Retrieve("uri").As<Json::String>();
        text_document_item.languageId = object.Retrieve("languageId").As<Json::String>();
        const Json::Any& version = object.Retrieve("version");
        if(version.IsUinteger())
            text_document_item.version = static_cast<Json::Integer>(version.As<Json::Uinteger>());
        else if(version.IsInteger())
            text_document_item.version = version.As<Json::Integer>();
        else
            std::abort();
        text_document_item.text = object.Retrieve("text").As<Json::String>();
    }

    auto Serialize(Json::Object& object, const TextDocumentItem& text_document_item) noexcept ->
    void
    {
        object.fields.emplace_back("uri", text_document_item.uri);
        object.fields.emplace_back("languageId", text_document_item.languageId);
        object.fields.emplace_back("version", text_document_item.version);
        object.fields.emplace_back("text", text_document_item.text);
    }
}

#endif