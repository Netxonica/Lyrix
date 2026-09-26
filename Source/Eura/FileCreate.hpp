// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_create
#define lyrix_header_guard_eura_file_create
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] FileCreate final
    {
        std::string uri;
    };

    auto from_json(const nlohmann::json& object, FileCreate& file_create) noexcept -> void;

    auto to_json(nlohmann::json& object, const FileCreate& file_create) noexcept -> void;
}

#endif
#endif