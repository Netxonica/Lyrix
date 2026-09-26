// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineCompletionList.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineCompletionList& inline_completion_list)
    noexcept -> void
    {
        const nlohmann::json& items = object.at("items");
        for(const nlohmann::json& item : items)
            inline_completion_list.items.emplace_back(item.get<InlineCompletionItem>());
    }

    auto to_json(nlohmann::json& object, const InlineCompletionList& inline_completion_list)
    noexcept -> void
    {
        nlohmann::json items = nlohmann::json::array();
        for(const InlineCompletionItem& item : inline_completion_list.items)
            items.emplace_back(item);
        object["items"] = items;
    }
}

#endif