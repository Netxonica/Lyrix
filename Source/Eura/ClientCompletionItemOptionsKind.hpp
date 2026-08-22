// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_completion_item_options_kind
#define lyrix_header_guard_eura_client_completion_item_options_kind
#include "Eura/Json.hpp"
#include "Eura/CompletionItemKind.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientCompletionItemOptionsKind final
    {
        std::optional<std::vector<CompletionItemKind>> valueSet;
    };

    auto from_json(const nlohmann::json& object, ClientCompletionItemOptionsKind&
    client_completion_item_options_kind) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientCompletionItemOptionsKind&
    client_completion_item_options_kind) noexcept -> void;
}

#endif
#endif