// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_context
#define lyrix_header_guard_eura_completion_context
#include "Eura/Json.hpp"
#include "Eura/CompletionTriggerKind.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionContext final
    {
        CompletionTriggerKind triggerKind;

        std::optional<std::string> triggerCharacter;
    };

    auto from_json(const nlohmann::json& object, CompletionContext& completion_context) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const CompletionContext& completion_context) noexcept ->
    void;
}

#endif
#endif