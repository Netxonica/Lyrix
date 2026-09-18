// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidSaveTextDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidSaveTextDocumentParams&
    did_save_text_document_params) noexcept -> void
    {
        did_save_text_document_params.textDocument = object.at("textDocument").get<
        TextDocumentIdentifier>();
        if(object.contains("text"))
            did_save_text_document_params.text = object.at("text").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const DidSaveTextDocumentParams&
    did_save_text_document_params) noexcept -> void
    {
        object["textDocument"] = did_save_text_document_params.textDocument;
        if(did_save_text_document_params.text.has_value())
            object["text"] = *did_save_text_document_params.text;
    }
}

#endif