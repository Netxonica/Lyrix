// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_change_text_document_params
#define lyrix_header_guard_eura_did_change_text_document_params
#include "Eura/TextDocumentContentChangeEvent.hpp"
#include "Eura/VersionedTextDocumentIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] DidChangeTextDocumentParams final
    {
        VersionedTextDocumentIdentifier textDocument;

        std::vector<TextDocumentContentChangeEvent> contentChanges;
    };

    auto from_json(const nlohmann::json& object, DidChangeTextDocumentParams&
    did_change_text_document_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidChangeTextDocumentParams&
    did_change_text_document_params) noexcept -> void;
}

#endif
#endif