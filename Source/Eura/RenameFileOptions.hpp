// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_rename_file_options
#define lyrix_header_guard_eura_rename_file_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] RenameFileOptions final
    {
        std::optional<bool> overwrite, ignoreIfExists;
    };

    auto from_json(const nlohmann::json& object, RenameFileOptions& rename_file_options) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const RenameFileOptions& rename_file_options) noexcept ->
    void;
}

#endif
#endif