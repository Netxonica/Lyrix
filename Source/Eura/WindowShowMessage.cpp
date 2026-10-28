// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WindowShowMessage.hpp"
#include "Eura/Client.hpp"
#include "Eura/ShowMessageParams.hpp"
#include "Eura/NotificationMessage.hpp"

namespace Eura
{
    auto WindowShowMessage(std::mutex& mutex, const MessageType message_type, const std::string
    message) noexcept -> void
    {
        ShowMessageParams show_message_params;
        show_message_params.type = message_type;
        show_message_params.message = message;
        nlohmann::json response;
        to_json(response, show_message_params);
        NotificationMessage notification_message;
        notification_message.params = response;
        notification_message.jsonrpc = "2.0";
        notification_message.method = "window/showMessage";
        nlohmann::json notification;
        to_json(notification, notification_message);
        Client(mutex, notification.dump());
    }
}

#endif