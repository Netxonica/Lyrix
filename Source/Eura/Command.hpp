// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_command
#define lyrix_header_guard_eura_command
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] Command final
    {
        std::string title;

        std::optional<std::string> tooltip;

        std::string command;

        std::optional<nlohmann::json> arguments;
    };

    auto from_json(const nlohmann::json& object, Command& command) noexcept -> void;

    auto to_json(nlohmann::json& object, const Command& command) noexcept -> void;
}

#endif
#endif