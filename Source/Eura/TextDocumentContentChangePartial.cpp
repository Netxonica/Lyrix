// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentContentChangePartial.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentContentChangePartial&
    text_document_content_change_partial) noexcept -> void
    {
        text_document_content_change_partial.range = object.at("range").get<Range>();
        if(object.contains("rangeLength"))
            text_document_content_change_partial.rangeLength = object.at("rangeLength").get<std::
            uint32_t>();
        text_document_content_change_partial.text = object.at("text").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentContentChangePartial&
    text_document_content_change_partial) noexcept -> void
    {
        object["range"] = text_document_content_change_partial.range;
        if(text_document_content_change_partial.rangeLength.has_value())
            object["rangeLength"] = *text_document_content_change_partial.rangeLength;
        object["text"] = text_document_content_change_partial.text;
    }
}

#endif