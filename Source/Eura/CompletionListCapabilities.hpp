// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_list_capabilities
#define lyrix_header_guard_eura_completion_list_capabilities
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionListCapabilities final
    {
        std::optional<std::vector<std::string>> itemDefaults;

        std::optional<bool> applyKindSupport;
    };

    auto from_json(const nlohmann::json& object, CompletionListCapabilities&
    completion_list_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const CompletionListCapabilities&
    completion_list_capabilities) noexcept -> void;
}

#endif
#endif