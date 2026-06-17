// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_json
#define lyrix_header_guard_eura_json
#include "Eura/Any.hpp"
#include "Eura/Strings.hpp"

namespace Eura::Json
{
    using Root = Object;

    [[nodiscard]] auto Deserialize(const std::string_view content, Strings& strings) noexcept ->
    Root;

    [[nodiscard]] auto Serialize(const Root& root) noexcept -> std::string;
}

#endif
#endif