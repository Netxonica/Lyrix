// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_save_options
#define lyrix_header_guard_eura_save_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] SaveOptions final
    {
        std::optional<bool> includeText;
    };

    auto from_json(const nlohmann::json& object, SaveOptions& save_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const SaveOptions& save_options) noexcept -> void;
}

#endif
#endif