// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineCompletionClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineCompletionClientCapabilities&
    inline_completion_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            inline_completion_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
    }

    auto to_json(nlohmann::json& object, const InlineCompletionClientCapabilities&
    inline_completion_client_capabilities) noexcept -> void
    {
        if(inline_completion_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *inline_completion_client_capabilities.
            dynamicRegistration;
    }
}

#endif