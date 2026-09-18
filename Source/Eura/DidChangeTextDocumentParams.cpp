// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeTextDocumentParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidChangeTextDocumentParams&
    did_change_text_document_params) noexcept -> void
    {
        did_change_text_document_params.textDocument = object.at("textDocument").get<
        VersionedTextDocumentIdentifier>();
        const nlohmann::json& contentChanges = object.at("contentChanges");
        for(const nlohmann::json& contentChange : contentChanges)
        {
            if(contentChange.contains("range"))
                did_change_text_document_params.contentChanges.emplace_back(contentChange.get<
                TextDocumentContentChangePartial>());
            else
                did_change_text_document_params.contentChanges.emplace_back(contentChange.get<
                TextDocumentContentChangeWholeDocument>());
        }
    }

    auto to_json(nlohmann::json& object, const DidChangeTextDocumentParams&
    did_change_text_document_params) noexcept -> void
    {
        object["textDocument"] = did_change_text_document_params.textDocument;
        nlohmann::json contentChanges = nlohmann::json::array();
        for(const TextDocumentContentChangeEvent& contentChange : did_change_text_document_params.
        contentChanges)
            std::visit([&contentChanges](auto&& contentChange)
            {
                contentChanges.emplace_back(contentChange);
            }, contentChange);
        object["contentChanges"] = contentChanges;
    }
}

#endif