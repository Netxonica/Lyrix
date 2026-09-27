// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_message_action_item
#define lyrix_header_guard_eura_message_action_item
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] MessageActionItem final
    {
        std::string title;

        std::unordered_map<std::string, std::variant<std::string, bool, std::int32_t, nlohmann::
        json>> optional; // optional
    };

    auto from_json(const nlohmann::json& object, MessageActionItem& message_action_item) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const MessageActionItem& message_action_item) noexcept ->
    void;
}

#endif
#endif