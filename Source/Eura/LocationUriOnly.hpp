// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_location_uri_only
#define lyrix_header_guard_eura_location_uri_only
#include "Eura/Json.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] LocationUriOnly final
    {
        DocumentUri uri;
    };

    auto from_json(const nlohmann::json& object, LocationUriOnly& location_uri_only) noexcept ->
    void;

    auto to_json(nlohmann::json& object, const LocationUriOnly& location_uri_only) noexcept -> void
    ;
}

#endif
#endif