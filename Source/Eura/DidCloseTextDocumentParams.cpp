// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidCloseTextDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidCloseTextDocumentParams&
    did_close_text_document_params) noexcept -> void
    {
        did_close_text_document_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
    }

    auto to_json(nlohmann::json& object, const DidCloseTextDocumentParams&
    did_close_text_document_params) noexcept -> void
    {
        object["textDocument"] = did_close_text_document_params.textDocument;
    }
}

#endif