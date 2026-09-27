// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ShowMessageRequestParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ShowMessageRequestParams&
    show_message_request_params) noexcept -> void
    {
        show_message_request_params.type = object.at("type").get<MessageType>();
        show_message_request_params.message = object.at("message").get<std::string>();
        if(object.contains("actions"))
        {
            show_message_request_params.actions = std::vector<MessageActionItem>{};
            const nlohmann::json& actions = object.at("actions");
            for(const nlohmann::json& action : actions)
                show_message_request_params.actions->emplace_back(action.get<MessageActionItem>());
        }
    }

    auto to_json(nlohmann::json& object, const ShowMessageRequestParams&
    show_message_request_params) noexcept -> void
    {
        object["type"] = show_message_request_params.type;
        object["message"] = show_message_request_params.message;
        if(show_message_request_params.actions.has_value())
        {
            nlohmann::json actions = nlohmann::json::array();
            for(const MessageActionItem& action : *show_message_request_params.actions)
                actions.emplace_back(action);
            object["actions"] = actions;
        }
    }
}

#endif