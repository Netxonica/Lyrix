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
        if(object.contains("willSave"))
            text_document_sync_options.willSave = object.at("willSave").get<bool>();
        if(object.contains("willSaveWaitUntil"))
            text_document_sync_options.willSaveWaitUntil = object.at("willSaveWaitUntil").get<bool>
            ();
        if(object.contains("save"))
        {
            const nlohmann::json& save = object.at("save");
            if(save.is_boolean())
                text_document_sync_options.save = save.get<bool>();
            else
                text_document_sync_options.save = save.get<SaveOptions>();
        }
    }

    auto to_json(nlohmann::json& object, const TextDocumentSyncOptions& text_document_sync_options)
    noexcept -> void
    {
        if(text_document_sync_options.openClose.has_value())
            object["openClose"] = *text_document_sync_options.openClose;
        if(text_document_sync_options.change.has_value())
            object["change"] = *text_document_sync_options.change;
        if(text_document_sync_options.willSave.has_value())
            object["willSave"] = *text_document_sync_options.willSave;
        if(text_document_sync_options.willSaveWaitUntil.has_value())
            object["willSaveWaitUntil"] = *text_document_sync_options.willSaveWaitUntil;
        if(text_document_sync_options.save.has_value())
            std::visit([&object](auto&& save)
            {
                object["save"] = save;
            }, *text_document_sync_options.save);
    }
}

#endif