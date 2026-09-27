// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_show_message_params
#define lyrix_header_guard_eura_show_message_params
#include "Eura/Json.hpp"
#include "Eura/MessageType.hpp"

namespace Eura
{
    struct [[nodiscard]] ShowMessageParams final
    {
        MessageType type;

        std::string message;
    };

    auto from_json(const nlohmann::json& object, ShowMessageParams& show_message_params) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const ShowMessageParams& show_message_params) noexcept ->
    void;
}

#endif
#endif