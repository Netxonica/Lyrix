// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_did_open_text_document_params
#define lyrix_header_guard_eura_did_open_text_document_params
#include "Eura/TextDocumentItem.hpp"

namespace Eura
{
    struct [[nodiscard]] DidOpenTextDocumentParams final
    {
        TextDocumentItem textDocument;
    };

    auto from_json(const nlohmann::json& object, DidOpenTextDocumentParams&
    did_open_text_document_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const DidOpenTextDocumentParams&
    did_open_text_document_params) noexcept -> void;
}

#endif
#endif