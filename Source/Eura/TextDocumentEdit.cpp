// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentEdit.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, TextDocumentEdit& text_document_edit) noexcept ->
    void
    {
        Deserialize(object.Retrieve("textDocument").As<Json::Object>(), text_document_edit.
        textDocument);
        const Json::Array& edits = object.Retrieve("edits").As<Json::Array>();
        for(const Json::Any& fedit : edits)
        {
            const Json::Object& edit = fedit.As<Json::Object>();
            if(edit.Contains("snippet"))
            {
                SnippetTextEdit snippet_text_edit;
                Deserialize(edit, snippet_text_edit);
                text_document_edit.edits.emplace_back(std::move(snippet_text_edit));
            }
            else if(edit.Contains("annotationId"))
            {
                AnnotatedTextEdit annotated_text_edit;
                Deserialize(edit, annotated_text_edit);
                text_document_edit.edits.emplace_back(std::move(annotated_text_edit));
            }
            else
            {
                TextEdit text_edit;
                Deserialize(edit, text_edit);
                text_document_edit.edits.emplace_back(std::move(text_edit));
            }
        }
    }

    auto Serialize(Json::Object& object, const TextDocumentEdit& text_document_edit) noexcept ->
    void
    {
        Serialize(object.NestedObject("textDocument"), text_document_edit.textDocument);
        Json::Array& edits = object.NestedArray("edits");
        for(const std::variant<TextEdit, AnnotatedTextEdit, SnippetTextEdit>& edit :
        text_document_edit.edits)
        {
            edits.emplace_back(Json::Object{});
            if(std::holds_alternative<TextEdit>(edit))
                Serialize(edits.back().As<Json::Object>(), std::get<TextEdit>(edit));
            else if(std::holds_alternative<AnnotatedTextEdit>(edit))
                Serialize(edits.back().As<Json::Object>(), std::get<AnnotatedTextEdit>(edit));
            else
                Serialize(edits.back().As<Json::Object>(), std::get<SnippetTextEdit>(edit));
        }
    }
}

#endif