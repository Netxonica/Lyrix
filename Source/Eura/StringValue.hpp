// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_string_value
#define lyrix_header_guard_eura_string_value
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] StringValue final
    {
        Json::String kind, value;
    };

    auto Deserialize(const Json::Object& object, StringValue& string_value) noexcept -> void;

    auto Serialize(Json::Object& object, const StringValue& string_value) noexcept -> void;
}

#endif
#endif