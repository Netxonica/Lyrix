// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_options
#define lyrix_header_guard_eura_completion_options
#include "Eura/WorkDoneProgressOptions.hpp"
#include "Eura/ServerCompletionItemOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionOptions final : WorkDoneProgressOptions
    {
        std::optional<std::vector<std::string>> triggerCharacters, allCommitCharacters;

        std::optional<bool> resolveProvider;

        std::optional<ServerCompletionItemOptions> completionItem;
    };

    auto from_json(const nlohmann::json& object, CompletionOptions& completion_options) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const CompletionOptions& completion_options) noexcept ->
    void;
}

#endif
#endif