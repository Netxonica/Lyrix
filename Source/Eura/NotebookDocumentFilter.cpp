// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentFilter.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, NotebookDocumentFilter& notebook_document_filter)
    noexcept -> void
    {
        if(object.Contains("notebookType"))
            notebook_document_filter.notebookType = object.Retrieve("notebookType").As<Json::String
            >();
        if(object.Contains("scheme"))
            notebook_document_filter.scheme = object.Retrieve("scheme").As<Json::String>();
        if(object.Contains("pattern"))
        {
            const Json::Any& pattern = object.Retrieve("pattern");
            if(pattern.IsString())
                notebook_document_filter.pattern = pattern.As<Json::String>();
            else if(pattern.IsObject())
            {
                RelativePattern relative_pattern;
                Deserialize(pattern.As<Json::Object>(), relative_pattern);
                notebook_document_filter.pattern = relative_pattern;
            }
            else
                std::abort();
        }
    }

    auto Serialize(Json::Object& object, const NotebookDocumentFilter& notebook_document_filter)
    noexcept -> void
    {
        if(notebook_document_filter.notebookType.has_value())
            object.fields.emplace_back("notebookType", *notebook_document_filter.notebookType);
        if(notebook_document_filter.scheme.has_value())
            object.fields.emplace_back("scheme", *notebook_document_filter.scheme);
        if(notebook_document_filter.pattern.has_value())
        {
            if(std::holds_alternative<Pattern>(*notebook_document_filter.pattern))
                object.fields.emplace_back("pattern", std::get<Pattern>(*notebook_document_filter.
                pattern));
            else
                Serialize(object.NestedObject("pattern"), std::get<RelativePattern>(*
                notebook_document_filter.pattern));
        }
    }
}

#endif