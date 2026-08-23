// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_client_folding_range_options
#define lyrix_header_guard_eura_client_folding_range_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] ClientFoldingRangeOptions final
    {
        std::optional<bool> collapsedText;
    };

    auto from_json(const nlohmann::json& object, ClientFoldingRangeOptions&
    client_folding_range_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const ClientFoldingRangeOptions&
    client_folding_range_options) noexcept -> void;
}

#endif
#endif