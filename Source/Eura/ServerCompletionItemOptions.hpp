// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_server_completion_item_options
#define lyrix_header_guard_eura_server_completion_item_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ServerCompletionItemOptions final
    {
        std::optional<bool> labelDetailsSupport;
    };

    auto from_json(const nlohmann::json& object, ServerCompletionItemOptions&
    server_completion_item_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ServerCompletionItemOptions&
    server_completion_item_options) noexcept -> void;
}

#endif
#endif