// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_notification_message
#define lyrix_header_guard_eura_notification_message
#include "Eura/Message.hpp"

namespace Eura
{
    struct [[nodiscard]] NotificationMessage final : Message
    {
        std::string method;

        std::optional<nlohmann::json> params;
    };

    auto from_json(const nlohmann::json& object, NotificationMessage& notitification_message)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const NotificationMessage& notification_message) noexcept
    -> void;
}

#endif
#endif