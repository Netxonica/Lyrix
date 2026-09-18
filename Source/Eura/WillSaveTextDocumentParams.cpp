// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WillSaveTextDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WillSaveTextDocumentParams&
    will_save_text_document_params) noexcept -> void
    {
        will_save_text_document_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        will_save_text_document_params.reason = object.at("reason").get<TextDocumentSaveReason>();
    }

    auto to_json(nlohmann::json& object, const WillSaveTextDocumentParams&
    will_save_text_document_params) noexcept -> void
    {
        object["textDocument"] = will_save_text_document_params.textDocument;
        object["reason"] = will_save_text_document_params.reason;
    }
}

#endif