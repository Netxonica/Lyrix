// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_location_uri_only
#define lyrix_header_guard_eura_location_uri_only
#include "Eura/Any.hpp"
#include "Eura/DocumentUri.hpp"

namespace Eura
{
    struct [[nodiscard]] LocationUriOnly final
    {
        DocumentUri uri;
    };

    auto Deserialize(const Json::Object& object, LocationUriOnly& location_uri_only) noexcept ->
    void;

    auto Serialize(Json::Object& object, const LocationUriOnly& location_uri_only) noexcept -> void
    ;
}

#endif
#endif