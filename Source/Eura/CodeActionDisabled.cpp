// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CodeActionDisabled.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CodeActionDisabled& code_action_disabled) noexcept
    -> void
    {
        code_action_disabled.reason = object.at("reason").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const CodeActionDisabled& code_action_disabled) noexcept
    -> void
    {
        object["reason"] = code_action_disabled.reason;
    }
}

#endif