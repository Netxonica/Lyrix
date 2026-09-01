// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ShowMessageRequestClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ShowMessageRequestClientCapabilities&
    show_message_request_client_capabilities) noexcept -> void
    {
        if(object.contains("messageActionItem"))
            show_message_request_client_capabilities.messageActionItem = object.at(
            "messageActionItem").get<ClientShowMessageActionItemOptions>();
    }

    auto to_json(nlohmann::json& object, const ShowMessageRequestClientCapabilities&
    show_message_request_client_capabilities) noexcept -> void
    {
        if(show_message_request_client_capabilities.messageActionItem.has_value())
            object["messageActionItem"] = *show_message_request_client_capabilities.
            messageActionItem;
    }
}

#endif