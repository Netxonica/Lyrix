// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentResult.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentContentResult&
    text_document_content_result) noexcept -> void
    {
        text_document_content_result.text = object.at("text").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentContentResult&
    text_document_content_result) noexcept -> void
    {
        object["text"] = text_document_content_result.text;
    }
}

#endif