// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentSyncOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentSyncOptions&
    text_document_sync_options) noexcept -> void
    {
        if(object.contains("openClose"))
            text_document_sync_options.openClose = object.at("openClose").get<bool>();
        if(object.contains("change"))
            text_document_sync_options.change = object.at("change").get<TextDocumentSyncKind>();
    }

    auto to_json(nlohmann::json& object, const TextDocumentSyncOptions& text_document_sync_options)
    noexcept -> void
    {
        if(text_document_sync_options.openClose.has_value())
            object["openClose"] = *text_document_sync_options.openClose;
        if(text_document_sync_options.change.has_value())
            object["change"] = *text_document_sync_options.change;
    }
}

#endif