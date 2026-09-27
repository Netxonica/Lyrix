// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MessageActionItem.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, MessageActionItem& message_action_item) noexcept
    -> void
    {
        message_action_item.title = object.at("title").get<std::string>();
        for(const auto& [key, value] : object.items())
            if(key not_eq "title")
            {
                if(value.is_string())
                    message_action_item.optional.emplace(key, value.get<std::string>());
                else if(value.is_boolean())
                    message_action_item.optional.emplace(key, value.get<bool>());
                else if(value.is_number_integer())
                    message_action_item.optional.emplace(key, value.get<std::int32_t>());
                else
                    message_action_item.optional.emplace(key, value);
            }
    }

    auto to_json(nlohmann::json& object, const MessageActionItem& message_action_item) noexcept ->
    void
    {
        object["title"] = message_action_item.title;
        for(const auto& [key, value] : message_action_item.optional)
            std::visit([&object, &key](auto&& value)
            {
                object[key] = value;
            }, value);
    }
}

#endif