// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_code_description
#define lyrix_header_guard_eura_code_description
#include "Eura/Any.hpp"
#include "Eura/URI.hpp"

namespace Eura
{
    struct [[nodiscard]] CodeDescription final
    {
        URI href;
    };

    auto Deserialize(const Json::Object& object, CodeDescription& code_description) noexcept ->
    void;

    auto Serialize(Json::Object& object, const CodeDescription& code_description) noexcept -> void;
}

#endif
#endif