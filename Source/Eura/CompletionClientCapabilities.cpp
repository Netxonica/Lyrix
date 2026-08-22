// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionClientCapabilities&
    completion_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            completion_client_capabilities.dynamicRegistration = object.at("dynamicRegistration").
            get<bool>();
        if(object.contains("completionItem"))
            completion_client_capabilities.completionItem = object.at("completionItem").get<
            ClientCompletionItemOptions>();
        if(object.contains("completionItemKind"))
            completion_client_capabilities.completionItemKind = object.at("completionItemKind").get
            <ClientCompletionItemOptionsKind>();
        if(object.contains("contextSupport"))
            completion_client_capabilities.contextSupport = object.at("contextSupport").get<bool>()
            ;
        if(object.contains("insertTextMode"))
            completion_client_capabilities.insertTextMode = object.at("insertTextMode").get<
            InsertTextMode>();
        if(object.contains("completionList"))
            completion_client_capabilities.completionList = object.at("completionList").get<
            CompletionListCapabilities>();
    }

    auto to_json(nlohmann::json& object, const CompletionClientCapabilities&
    completion_client_capabilities) noexcept -> void
    {
        if(completion_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *completion_client_capabilities.dynamicRegistration;
        if(completion_client_capabilities.completionItem.has_value())
            object["completionItem"] = *completion_client_capabilities.completionItem;
        if(completion_client_capabilities.completionItemKind.has_value())
            object["completionItemKind"] = *completion_client_capabilities.completionItemKind;
        if(completion_client_capabilities.contextSupport.has_value())
            object["contextSupport"] = *completion_client_capabilities.contextSupport;
        if(completion_client_capabilities.insertTextMode.has_value())
            object["insertTextMode"] = *completion_client_capabilities.insertTextMode;
        if(completion_client_capabilities.completionList.has_value())
            object["completionList"] = *completion_client_capabilities.completionList;
    }
}

#endif