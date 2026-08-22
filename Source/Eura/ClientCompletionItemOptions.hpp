// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_completion_item_options
#define lyrix_header_guard_eura_client_completion_item_options
#include "Eura/MarkupKind.hpp"
#include "Eura/CompletionItemTagOptions.hpp"
#include "Eura/ClientCompletionItemResolveOptions.hpp"
#include "Eura/ClientCompletionItemInsertTextModeOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientCompletionItemOptions final
    {
        std::optional<bool> snippetSupport, commitCharactersSupport;

        std::optional<std::vector<MarkupKind>> documentationFormat;

        std::optional<bool> deprecatedSupport, preselectSupport;

        std::optional<CompletionItemTagOptions> tagSupport;

        std::optional<bool> insertReplaceSupport;

        std::optional<ClientCompletionItemResolveOptions> resolveSupport;

        std::optional<ClientCompletionItemInsertTextModeOptions> insertTextModeSupport;

        std::optional<bool> labelDetailsSupport;
    };

    auto from_json(const nlohmann::json& object, ClientCompletionItemOptions&
    client_completion_item_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientCompletionItemOptions&
    client_completion_item_options) noexcept -> void;
}

#endif
#endif