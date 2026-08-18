// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotificationMessage.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, NotificationMessage& notification_message)
    noexcept -> void
    {
        from_json(object, static_cast<Message&>(notification_message));
        notification_message.method = object.at("method").get<std::string>();
        if(object.contains("params"))
            notification_message.params = object.at("params");
    }

    auto to_json(nlohmann::json& object, const NotificationMessage& notification_message) noexcept
    -> void
    {
        to_json(object, static_cast<const Message&>(notification_message));
        object["method"] = notification_message.method;
        if(notification_message.params.has_value())
            object["params"] = *notification_message.params;
    }
}

#endif