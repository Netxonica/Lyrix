// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_initialize_result
#define lyrix_header_guard_eura_initialize_result
#include "Eura/ServerInfo.hpp"
#include "Eura/ServerCapabilities.hpp"

namespace Eura
{
    struct [[nodiscard]] InitializeResult final
    {
        ServerCapabilities capabilities;

        std::optional<ServerInfo> serverInfo;
    };

    auto from_json(const nlohmann::json& object, InitializeResult& initialize_result) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const InitializeResult& initialize_result) noexcept ->
    void;
}

#endif
#endif