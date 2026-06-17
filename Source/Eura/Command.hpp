// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_command
#define lyrix_header_guard_eura_command
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] Command final
    {
        Json::String title;

        std::optional<Json::String> tooltip;

        Json::String command;

        std::optional<std::vector<Json::Any>> arguments;
    };

    auto Deserialize(const Json::Object& object, Command& command) noexcept -> void;

    auto Serialize(Json::Object& object, const Command& command) noexcept -> void;
}

#endif
#endif