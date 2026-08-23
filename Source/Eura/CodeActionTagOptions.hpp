// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action_tag_options
#define lyrix_header_guard_eura_code_action_tag_options
#include "Eura/Json.hpp"
#include "Eura/CodeActionTag.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeActionTagOptions final
    {
        std::vector<CodeActionTag> valueSet;
    };

    auto from_json(const nlohmann::json& object, CodeActionTagOptions& code_action_tag_options)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const CodeActionTagOptions& code_action_tag_options)
    noexcept -> void;
}

#endif
#endif