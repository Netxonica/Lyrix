// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_relative_pattern
#define lyrix_header_guard_eura_relative_pattern
#include "Eura/Pattern.hpp"
#include "Eura/WorkspaceFolder.hpp"

namespace Eura
{
    struct [[nodiscard]] RelativePattern final
    {
        std::variant<WorkspaceFolder, URI> baseUri;

        Pattern pattern;
    };

    auto from_json(const nlohmann::json& object, RelativePattern& relative_pattern) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const RelativePattern& relative_pattern) noexcept -> void;
}

#endif
#endif