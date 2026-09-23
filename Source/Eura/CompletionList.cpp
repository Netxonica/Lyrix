// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionList.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionList& completion_list) noexcept -> void
    {
        completion_list.isIncomplete = object.at("isIncomplete").get<bool>();
        if(object.contains("itemDefaults"))
            completion_list.itemDefaults = object.at("itemDefaults").get<CompletionItemDefaults>();
        if(object.contains("applyKind"))
            completion_list.applyKind = object.at("applyKind").get<CompletionItemApplyKinds>();
        const nlohmann::json& items = object.at("items");
        for(const nlohmann::json& item : items)
            completion_list.items.emplace_back(item.get<CompletionItem>());
    }

    auto to_json(nlohmann::json& object, const CompletionList& completion_list) noexcept -> void
    {
        object["isIncomplete"] = completion_list.isIncomplete;
        if(completion_list.itemDefaults.has_value())
            object["itemDefaults"] = *completion_list.itemDefaults;
        if(completion_list.applyKind.has_value())
            object["applyKind"] = *completion_list.applyKind;
        nlohmann::json items = nlohmann::json::array();
        for(const CompletionItem& item : completion_list.items)
            items.emplace_back(item);
        object["items"] = items;
    }
}

#endif