// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientShowMessageActionItemOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientShowMessageActionItemOptions&
    client_show_message_action_item_options) noexcept -> void
    {
        if(object.contains("additionalPropertiesSupport"))
            client_show_message_action_item_options.additionalPropertiesSupport = object.at(
            "additionalPropertiesSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const ClientShowMessageActionItemOptions&
    client_show_message_action_item_options) noexcept -> void
    {
        if(client_show_message_action_item_options.additionalPropertiesSupport.has_value())
            object["additionalPropertiesSupport"] = *client_show_message_action_item_options.
            additionalPropertiesSupport;
    }
}

#endif