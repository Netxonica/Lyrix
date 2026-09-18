// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentChangeWholeDocument.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentContentChangeWholeDocument&
    text_document_content_change_whole_document) noexcept -> void
    {
        text_document_content_change_whole_document.text = object.at("text").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentContentChangeWholeDocument&
    text_document_content_change_whole_document) noexcept -> void
    {
        object["text"] = text_document_content_change_whole_document.text;
    }
}

#endif