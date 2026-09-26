// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineCompletionItem.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineCompletionItem& inline_completion_item)
    noexcept -> void
    {
        const nlohmann::json& insertText = object.at("insertText");
        if(insertText.is_string())
            inline_completion_item.insertText = insertText.get<std::string>();
        else
            inline_completion_item.insertText = insertText.get<StringValue>();
        if(object.contains("filterText"))
            inline_completion_item.filterText = object.at("filterText").get<std::string>();
        if(object.contains("range"))
            inline_completion_item.range = object.at("range").get<Range>();
        if(object.contains("command"))
            inline_completion_item.command = object.at("command").get<Command>();
    }

    auto to_json(nlohmann::json& object, const InlineCompletionItem& inline_completion_item)
    noexcept -> void
    {
        std::visit([&object](auto&& insertText)
        {
            object["insertText"] = insertText;
        }, inline_completion_item.insertText);
        if(inline_completion_item.filterText.has_value())
            object["filterText"] = *inline_completion_item.filterText;
        if(inline_completion_item.range.has_value())
            object["range"] = *inline_completion_item.range;
        if(inline_completion_item.command.has_value())
            object["command"] = *inline_completion_item.command;
    }
}

#endif