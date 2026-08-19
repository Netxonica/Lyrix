// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentEdit.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentEdit& text_document_edit) noexcept ->
    void
    {
        text_document_edit.textDocument = object.at("textDocument").get<
        OptionalVersionedTextDocumentIdentifier>();
        const nlohmann::json& edits = object.at("edits");
        for(const nlohmann::json& edit : edits)
        {
            if(edit.contains("snippet"))
                text_document_edit.edits.emplace_back(edit.get<SnippetTextEdit>());
            else if(edit.contains("annotationId"))
                text_document_edit.edits.emplace_back(edit.get<AnnotatedTextEdit>());
            else
                text_document_edit.edits.emplace_back(edit.get<TextEdit>());
        }
    }

    auto to_json(nlohmann::json& object, const TextDocumentEdit& text_document_edit) noexcept ->
    void
    {
        object["textDocument"] = text_document_edit.textDocument;
        nlohmann::json edits = nlohmann::json::array();
        for(const std::variant<TextEdit, AnnotatedTextEdit, SnippetTextEdit>& edit :
        text_document_edit.edits)
            std::visit([&edits](auto&& edit)
            {
                edits += edit;
            }, edit);
        object["edits"] = edits;
    }
}

#endif