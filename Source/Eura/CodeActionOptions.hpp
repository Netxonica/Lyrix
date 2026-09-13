// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_action_options
#define lyrix_header_guard_eura_code_action_options
#include "Eura/WorkDoneProgressOptions.hpp"
#include "Eura/CodeActionKindDocumentation.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeActionOptions final : WorkDoneProgressOptions
    {
        std::optional<std::vector<CodeActionKind>> codeActionKinds;

        std::optional<std::vector<CodeActionKindDocumentation>> documentation;

        std::optional<bool> resolveProvider;
    };

    auto from_json(const nlohmann::json& object, CodeActionOptions& code_action_options) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const CodeActionOptions& code_action_options) noexcept ->
    void;
}

#endif
#endif