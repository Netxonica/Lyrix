// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookCellTextDocumentFilter.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, NotebookCellTextDocumentFilter&
    notebook_cell_text_document_filter) noexcept -> void
    {
        const Json::Any& notebook = object.Retrieve("notebook");
        if(notebook.IsString())
            notebook_cell_text_document_filter.notebook = notebook.As<Json::String>();
        else if(notebook.IsObject())
        {
            NotebookDocumentFilter notebook_document_filter;
            Deserialize(notebook.As<Json::Object>(), notebook_document_filter);
            notebook_cell_text_document_filter.notebook = notebook_document_filter;
        }
        if(object.Contains("language"))
            notebook_cell_text_document_filter.language = object.Retrieve("language").As<Json::
            String>();
    }

    auto Serialize(Json::Object& object, const NotebookCellTextDocumentFilter&
    notebook_cell_text_document_filter) noexcept -> void
    {
        if(std::holds_alternative<Json::String>(notebook_cell_text_document_filter.notebook))
            object.fields.emplace_back("notebook", std::get<Json::String>(
            notebook_cell_text_document_filter.notebook));
        else
            Serialize(object.NestedObject("notebook"), std::get<NotebookDocumentFilter>(
            notebook_cell_text_document_filter.notebook));
    }
}

#endif