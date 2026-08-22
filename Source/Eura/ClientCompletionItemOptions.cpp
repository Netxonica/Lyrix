// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientCompletionItemOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientCompletionItemOptions&
    client_completion_item_options) noexcept -> void
    {
        if(object.contains("snippetSupport"))
            client_completion_item_options.snippetSupport = object.at("snippetSupport").get<bool>()
            ;
        if(object.contains("commitCharactersSupport"))
            client_completion_item_options.commitCharactersSupport = object.at(
            "commitCharactersSupport").get<bool>();
        if(object.contains("documentationFormat"))
        {
            client_completion_item_options.documentationFormat = std::vector<MarkupKind>{};
            const nlohmann::json& documentationFormat = object.at("documentationFormat");
            for(const nlohmann::json& documentation : documentationFormat)
                client_completion_item_options.documentationFormat->emplace_back(documentation.get<
                MarkupKind>());
        }
        if(object.contains("deprecatedSupport"))
            client_completion_item_options.deprecatedSupport = object.at("deprecatedSupport").get<
            bool>();
        if(object.contains("preselectSupport"))
            client_completion_item_options.preselectSupport = object.at("preselectSupport").get<
            bool>();
        if(object.contains("tagSupport"))
            client_completion_item_options.tagSupport = object.at("tagSupport").get<
            CompletionItemTagOptions>();
        if(object.contains("insertReplaceSupport"))
            client_completion_item_options.insertReplaceSupport = object.at("insertReplaceSupport")
            .get<bool>();
        if(object.contains("resolveSupport"))
            client_completion_item_options.resolveSupport = object.at("resolveSupport").get<
            ClientCompletionItemResolveOptions>();
        if(object.contains("insertTextModeSupport"))
            client_completion_item_options.insertTextModeSupport = object.at(
            "insertTextModeSupport").get<ClientCompletionItemInsertTextModeOptions>();
        if(object.contains("labelDetailsSupport"))
            client_completion_item_options.labelDetailsSupport = object.at("labelDetailsSupport").
            get<bool>();
    }

    auto to_json(nlohmann::json& object, const ClientCompletionItemOptions&
    client_completion_item_options) noexcept -> void
    {
        if(client_completion_item_options.snippetSupport.has_value())
            object["snippetSupport"] = *client_completion_item_options.snippetSupport;
        if(client_completion_item_options.commitCharactersSupport.has_value())
            object["commitCharactersSupport"] = *client_completion_item_options.
            commitCharactersSupport;
        if(client_completion_item_options.documentationFormat.has_value())
        {
            nlohmann::json documentationFormat = nlohmann::json::array();
            for(const MarkupKind& documentation : *client_completion_item_options.
            documentationFormat)
                documentationFormat.emplace_back(documentation);
            object["documentationFormat"] = documentationFormat;
        }
        if(client_completion_item_options.deprecatedSupport.has_value())
            object["deprecatedSupport"] = *client_completion_item_options.deprecatedSupport;
        if(client_completion_item_options.preselectSupport.has_value())
            object["preselectSupport"] = *client_completion_item_options.preselectSupport;
        if(client_completion_item_options.tagSupport.has_value())
            object["tagSupport"] = *client_completion_item_options.tagSupport;
        if(client_completion_item_options.insertReplaceSupport.has_value())
            object["insertReplaceSupport"] = *client_completion_item_options.insertReplaceSupport;
        if(client_completion_item_options.resolveSupport.has_value())
            object["resolveSupport"] = *client_completion_item_options.resolveSupport;
        if(client_completion_item_options.insertTextModeSupport.has_value())
            object["insertTextModeSupport"] = *client_completion_item_options.insertTextModeSupport
            ;
        if(client_completion_item_options.labelDetailsSupport.has_value())
            object["labelDetailsSupport"] = *client_completion_item_options.labelDetailsSupport;
    }
}

#endif