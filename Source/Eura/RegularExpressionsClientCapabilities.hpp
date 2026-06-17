// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_regular_expressions_client_capabilities
#define lyrix_header_guard_eura_regular_expressions_client_capabilities
#include "Eura/Any.hpp"
#include "Eura/RegularExpressionEngineKind.hpp"

namespace Eura
{
    struct [[nodiscard]] RegularExpressionsClientCapabilities final
    {
        RegularExpressionEngineKind engine;

        std::optional<Json::String> version;
    };

    auto Deserialize(const Json::Object& object, RegularExpressionsClientCapabilities&
    regular_expressions_client_capabilities) noexcept -> void;

    auto Serialize(Json::Object& object, const RegularExpressionsClientCapabilities&
    regular_expressions_client_capabilities) noexcept -> void;
}

#endif
#endif