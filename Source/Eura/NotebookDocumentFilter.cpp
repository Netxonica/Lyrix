// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentFilter.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotebookDocumentFilter& notebook_document_filter)
    noexcept -> void
    {
        if(object.contains("notebookType"))
            notebook_document_filter.notebookType = object.at("notebookType").get<std::string>();
        if(object.contains("scheme"))
            notebook_document_filter.scheme = object.at("scheme").get<std::string>();
        if(object.contains("pattern"))
        {
            const nlohmann::json& pattern = object.at("pattern");
            if(pattern.is_string())
                notebook_document_filter.pattern = pattern.get<Pattern>();
            else
                notebook_document_filter.pattern = pattern.get<RelativePattern>();
        }
    }

    auto to_json(nlohmann::json& object, const NotebookDocumentFilter& notebook_document_filter)
    noexcept -> void
    {
        if(notebook_document_filter.notebookType.has_value())
            object["notebookType"] = *notebook_document_filter.notebookType;
        if(notebook_document_filter.scheme.has_value())
            object["scheme"] = *notebook_document_filter.scheme;
        if(notebook_document_filter.pattern.has_value())
            std::visit([&object](auto&& pattern)
            {
                object["pattern"] = pattern;
            }, *notebook_document_filter.pattern);
    }
}

#endif