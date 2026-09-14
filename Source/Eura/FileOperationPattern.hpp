// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_operation_pattern
#define lyrix_header_guard_eura_file_operation_pattern
#include "Eura/FileOperationPatternKind.hpp"
#include "Eura/FileOperationPatternOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] FileOperationPattern final
    {
        std::string glob;

        std::optional<FileOperationPatternKind> matches;

        std::optional<FileOperationPatternOptions> options;
    };

    auto from_json(const nlohmann::json& object, FileOperationPattern& file_operation_pattern)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const FileOperationPattern& file_operation_pattern)
    noexcept -> void;
}

#endif
#endif