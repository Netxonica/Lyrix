// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_will_save_text_document_params
#define lyrix_header_guard_eura_will_save_text_document_params
#include "Eura/TextDocumentIdentifier.hpp"
#include "Eura/TextDocumentSaveReason.hpp"

namespace Eura
{
    struct [[nodiscard]] WillSaveTextDocumentParams final
    {
        TextDocumentIdentifier textDocument;

        TextDocumentSaveReason reason;
    };

    auto from_json(const nlohmann::json& object, WillSaveTextDocumentParams&
    will_save_text_document_params) noexcept -> void;

    auto to_json(nlohmann::json& object, const WillSaveTextDocumentParams&
    will_save_text_document_params) noexcept -> void;
}

#endif
#endif