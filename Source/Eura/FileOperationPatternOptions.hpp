// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_operation_pattern_options
#define lyrix_header_guard_eura_file_operation_pattern_options
#include "Eura/Json.hpp"

namespace Eura
{
    struct [[nodiscard]] FileOperationPatternOptions final
    {
        std::optional<bool> ignoreCase;
    };

    auto from_json(const nlohmann::json& object, FileOperationPatternOptions&
    file_operation_pattern_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const FileOperationPatternOptions&
    file_operation_pattern_options) noexcept -> void;
}

#endif
#endif