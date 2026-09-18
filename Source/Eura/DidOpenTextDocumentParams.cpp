// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidOpenTextDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidOpenTextDocumentParams&
    did_open_text_document_params) noexcept -> void
    {
        did_open_text_document_params.textDocument = object.at("textDocument").get<TextDocumentItem
        >();
    }

    auto to_json(nlohmann::json& object, const DidOpenTextDocumentParams&
    did_open_text_document_params) noexcept -> void
    {
        object["textDocument"] = did_open_text_document_params.textDocument;
    }
}

#endif