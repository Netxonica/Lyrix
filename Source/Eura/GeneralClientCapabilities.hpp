// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_general_client_capabilities
#define lyrix_header_guard_eura_general_client_capabilities
#include "Eura/PositionEncodingKind.hpp"
#include "Eura/MarkdownClientCapabilities.hpp"
#include "Eura/StaleRequestSupportOptions.hpp"
#include "Eura/RegularExpressionsClientCapabilities.hpp"

namespace Eura
{
    struct [[nodiscard]] GeneralClientCapabilities final
    {
        std::optional<StaleRequestSupportOptions> staleRequestSupport;

        std::optional<RegularExpressionsClientCapabilities> regularExpressions;

        std::optional<MarkdownClientCapabilities> markdown;

        std::optional<std::vector<PositionEncodingKind>> positionEncodings;
    };

    auto from_json(const nlohmann::json& object, GeneralClientCapabilities&
    general_client_capabilities) noexcept -> void;

    auto to_json(nlohmann::json& object, const GeneralClientCapabilities&
    general_client_capabilities) noexcept -> void;
}

#endif
#endif