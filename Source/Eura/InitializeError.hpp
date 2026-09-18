// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_initialize_error
#define lyrix_header_guard_eura_initialize_error
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] InitializeError final
    {
        bool retry;
    };

    auto from_json(const nlohmann::json& object, InitializeError& initialize_error) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const InitializeError& initialize_error) noexcept -> void;
}

#endif
#endif