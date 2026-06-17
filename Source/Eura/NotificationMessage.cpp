// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotificationMessage.hpp"

namespace Eura
{
    auto Deserialize(Json::Object& object, NotificationMessage& notification_message) noexcept ->
    void
    {
        Deserialize(object, static_cast<Message&>(notification_message));
        notification_message.method = object.Retrieve("method").As<Json::String>();
        if(object.Contains("params"))
        {
            Json::Any& params = object.Retrieve("params");
            if(params.IsObject())
                notification_message.params = std::move(params.As<Json::Object>());
            else if(params.IsArray())
                notification_message.params = std::move(params.As<Json::Array>());
            else
                std::abort();
        }
    }

    auto Serialize(Json::Object& object, NotificationMessage& notification_message) noexcept ->
    void
    {
        Serialize(object, static_cast<const Message&>(notification_message));
        object.fields.emplace_back("method", notification_message.method);
        if(notification_message.params.has_value())
            notification_message.params->visit([&object](auto&& params)
            {
                object.fields.emplace_back("params", std::move(params));
            });
    }
}

#endif