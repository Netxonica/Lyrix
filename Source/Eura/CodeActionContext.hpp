// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action_context
#define lyrix_header_guard_eura_code_action_context
#include "Eura/Diagnostic.hpp"
#include "Eura/CodeActionKind.hpp"
#include "Eura/CodeActionTriggerKind.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeActionContext final
    {
        std::vector<Diagnostic> diagnostics;

        std::optional<std::vector<CodeActionKind>> only;

        std::optional<CodeActionTriggerKind> triggerKind;
    };

    auto from_json(const nlohmann::json& object, CodeActionContext& code_action_context) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const CodeActionContext& code_action_context) noexcept ->
    void;
}

#endif
#endif