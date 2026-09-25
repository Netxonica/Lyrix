// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action_disabled
#define lyrix_header_guard_eura_code_action_disabled
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeActionDisabled final
    {
        std::string reason;
    };

    auto from_json(const nlohmann::json& object, CodeActionDisabled& code_action_disabled) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const CodeActionDisabled& code_action_disabled) noexcept
    -> void;
}

#endif
#endif