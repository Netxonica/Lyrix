// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_markdown_client_capabilities
#define lyrix_header_guard_eura_markdown_client_capabilities
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] MarkdownClientCapabilities final
    {
        Json::String parser;

        std::optional<Json::String> version;

        std::optional<std::vector<Json::String>> allowedTags;
    };

    auto Deserialize(const Json::Object& object, MarkdownClientCapabilities&
    markdown_client_capabilities) noexcept -> void;

    auto Serialize(Json::Object& object, const MarkdownClientCapabilities&
    markdown_client_capabilities) noexcept -> void;
}

#endif
#endif