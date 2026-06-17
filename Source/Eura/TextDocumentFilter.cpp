// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentFilter.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, TextDocumentFilter& text_document_filter) noexcept
    -> void
    {
        if(object.Contains("language"))
            text_document_filter.language = object.Retrieve("language").As<Json::String>();
        if(object.Contains("scheme"))
            text_document_filter.scheme = object.Retrieve("scheme").As<Json::String>();
        if(object.Contains("pattern"))
        {
            const Json::Any& pattern = object.Retrieve("pattern");
            if(pattern.IsString())
                text_document_filter.pattern = pattern.As<Pattern>();
            else if(pattern.IsObject())
            {
                RelativePattern relative_pattern;
                Deserialize(pattern.As<Json::Object>(), relative_pattern);
                text_document_filter.pattern = relative_pattern;
            }
            else
                std::abort();
        }
    }

    auto Serialize(Json::Object& object, const TextDocumentFilter& text_document_filter) noexcept -> void
    {
        if(text_document_filter.language.has_value())
            object.fields.emplace_back("language", *text_document_filter.language);
        if(text_document_filter.scheme.has_value())
            object.fields.emplace_back("scheme", *text_document_filter.scheme);
        if(text_document_filter.pattern.has_value())
        {
            if(std::holds_alternative<Pattern>(*text_document_filter.pattern))
                object.fields.emplace_back("pattern", std::get<Pattern>(*text_document_filter.
                pattern));
            else
                Serialize(object.NestedObject("pattern"), std::get<RelativePattern>(*
                text_document_filter.pattern));
        }
    }
}

#endif