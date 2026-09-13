// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action_kind_documentation
#define lyrix_header_guard_eura_code_action_kind_documentation
#include "Eura/Command.hpp"
#include "Eura/CodeActionKind.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeActionKindDocumentation final
    {
        CodeActionKind kind;

        Command command;
    };

    auto from_json(const nlohmann::json& object, CodeActionKindDocumentation&
    code_action_kind_documentation) noexcept -> void;

    auto to_json(nlohmann::json& object, const CodeActionKindDocumentation&
    code_action_kind_documentation) noexcept -> void;
}

#endif
#endif