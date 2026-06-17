// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_text_document_edit
#define lyrix_header_guard_eura_text_document_edit
#include "Eura/SnippetTextEdit.hpp"
#include "Eura/AnnotatedTextEdit.hpp"
#include "Eura/OptionalVersionedTextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] TextDocumentEdit final
    {
        OptionalVersionedTextDocumentIdentifier textDocument;

        std::vector<std::variant<TextEdit, AnnotatedTextEdit, SnippetTextEdit>> edits;
    };

    auto Deserialize(const Json::Object& object, TextDocumentEdit& text_document_edit) noexcept ->
    void;

    auto Serialize(Json::Object& object, const TextDocumentEdit& text_document_edit) noexcept ->
    void;
}

#endif
#endif