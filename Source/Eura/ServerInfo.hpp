// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_server_info
#define lyrix_header_guard_eura_server_info
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ServerInfo final
    {
        std::string name;

        std::optional<std::string> version;
    };

    auto from_json(const nlohmann::json& object, ServerInfo& server_info) noexcept -> void;

    auto to_json(nlohmann::json& object, const ServerInfo& server_info) noexcept -> void;
}

#endif
#endif