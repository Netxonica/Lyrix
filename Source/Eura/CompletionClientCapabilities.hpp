// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_completion_client_capabilities
#define lyrix_header_guard_eura_completion_client_capabilities
#include "Eura/CompletionListCapabilities.hpp"
#include "Eura/ClientCompletionItemOptions.hpp"
#include "Eura/ClientCompletionItemOptionsKind.hpp"

namespace Eura
{
    struct [[nodiscard]] CompletionClientCapabilities final
    {
        std::optional<bool> dynamicRegistration;

        std::optional<ClientCompletionItemOptions> completionItem;

        std::optional<ClientCompletionItemOptionsKind> completionItemKind;

        std::optional<bool> contextSupport;

        std::optional<InsertTextMode> insertTextMode;

        std::optional<CompletionListCapabilities> completionList;
    };

    auto from_json(const nlohmann::json& object, CompletionClientCapabilities&
    completion_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const CompletionClientCapabilities&
    completion_client_capabilities) noexcept -> void;
}

#endif
#endif