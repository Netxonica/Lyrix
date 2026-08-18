// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentFilter.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentFilter& text_document_filter) noexcept
    -> void
    {
        if(object.contains("language"))
            text_document_filter.language = object.at("language").get<std::string>();
        if(object.contains("scheme"))
            text_document_filter.scheme = object.at("scheme").get<std::string>();
        if(object.contains("pattern"))
        {
            const nlohmann::json& pattern = object.at("pattern");
            if(pattern.is_string())
                text_document_filter.pattern = pattern.get<Pattern>();
            else
                text_document_filter.pattern = pattern.get<RelativePattern>();
        }
    }

    auto to_json(nlohmann::json& object, const TextDocumentFilter& text_document_filter) noexcept
    -> void
    {
        if(text_document_filter.language.has_value())
            object["language"] = *text_document_filter.language;
        if(text_document_filter.scheme.has_value())
            object["scheme"] = *text_document_filter.scheme;
        if(text_document_filter.pattern.has_value())
            std::visit([&object](auto&& pattern)
            {
                object["pattern"] = pattern;
            }, *text_document_filter.pattern);
    }
}

#endif