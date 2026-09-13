// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationPatternOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileOperationPatternOptions&
    file_operation_pattern_options) noexcept -> void
    {
        if(object.contains("ignoreCase"))
            file_operation_pattern_options.ignoreCase = object.at("ignoreCase").get<bool>();
    }

    auto to_json(nlohmann::json& object, const FileOperationPatternOptions&
    file_operation_pattern_options) noexcept -> void
    {
        if(file_operation_pattern_options.ignoreCase.has_value())
            object["ignoreCase"] = *file_operation_pattern_options.ignoreCase;
    }
}

#endif