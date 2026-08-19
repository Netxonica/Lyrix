// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_markdown_client_capabilities
#define lyrix_header_guard_eura_markdown_client_capabilities
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] MarkdownClientCapabilities final
    {
        std::string parser;

        std::optional<std::string> version;

        std::optional<std::vector<std::string>> allowedTags;
    };

    auto from_json(const nlohmann::json& object, MarkdownClientCapabilities&
    markdown_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const MarkdownClientCapabilities&
    markdown_client_capabilities) noexcept -> void;
}

#endif
#endif