// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_operation_filter
#define lyrix_header_guard_eura_file_operation_filter
#include "Eura/FileOperationPattern.hpp"

namespace Eura
{
    struct [[nodiscard]] FileOperationFilter final
    {
        std::optional<std::string> scheme;

        FileOperationPattern pattern;
    };

    auto from_json(const nlohmann::json& object, FileOperationFilter& file_operation_filter)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const FileOperationFilter& file_operation_filter) noexcept
    -> void;
}

#endif
#endif