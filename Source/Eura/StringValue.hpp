// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_string_value
#define lyrix_header_guard_eura_string_value
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] StringValue final
    {
        std::string kind, value;
    };

    auto from_json(const nlohmann::json& object, StringValue& string_value) noexcept -> void;

    auto to_json(nlohmann::json& object, const StringValue& string_value) noexcept -> void;
}

#endif
#endif