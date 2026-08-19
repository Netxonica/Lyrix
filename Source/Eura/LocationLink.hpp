// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_location_link
#define lyrix_header_guard_eura_location_link
#include "Eura/Range.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] LocationLink final
    {
        std::optional<Range> originSelectionRange;

        DocumentUri targetUri;

        Range targetRange, targetSelectionRange;
    };

    auto from_json(const nlohmann::json& object, LocationLink& location_link) noexcept -> void;

    auto to_json(nlohmann::json& object, const LocationLink& location_link) noexcept -> void;
}

#endif
#endif