// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentItem.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentItem& text_document_item) noexcept ->
    void
    {
        text_document_item.uri = object.at("uri").get<DocumentUri>();
        text_document_item.languageId = object.at("languageId").get<std::string>();
        text_document_item.version = object.at("version").get<std::int32_t>();
        text_document_item.text = object.at("text").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentItem& text_document_item) noexcept ->
    void
    {
        object["uri"] = text_document_item.uri;
        object["languageId"] = text_document_item.languageId;
        object["version"] = text_document_item.version;
        object["text"] = text_document_item.text;
    }
}

#endif