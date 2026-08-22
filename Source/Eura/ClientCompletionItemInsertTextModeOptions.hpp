// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_completion_item_insert_text_mode_options
#define lyrix_header_guard_eura_client_completion_item_insert_text_mode_options
#include "Eura/Json.hpp"
#include "Eura/InsertTextMode.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientCompletionItemInsertTextModeOptions final
    {
        std::vector<InsertTextMode> valueSet;
    };

    auto from_json(const nlohmann::json& object, ClientCompletionItemInsertTextModeOptions&
    client_completion_item_insert_text_mode_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientCompletionItemInsertTextModeOptions&
    client_completion_item_insert_text_mode_options) noexcept -> void;
}

#endif
#endif