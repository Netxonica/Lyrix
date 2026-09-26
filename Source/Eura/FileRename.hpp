// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_rename
#define lyrix_header_guard_eura_file_rename
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] FileRename final
    {
        std::string oldUri, newUri;
    };

    auto from_json(const nlohmann::json& object, FileRename& file_rename) noexcept -> void;

    auto to_json(nlohmann::json& object, const FileRename& file_rename) noexcept -> void;
}

#endif
#endif