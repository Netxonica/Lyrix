// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_cancel_params
#define lyrix_header_guard_eura_cancel_params
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] CancelParams final
    {
        std::variant<Json::Integer, Json::String> id;
    };

    auto Deserialize(const Json::Object& object, CancelParams& cancel_params) noexcept -> void;

    auto Serialize(Json::Object& object, const CancelParams& cancel_params) noexcept -> void;
}

#endif
#endif