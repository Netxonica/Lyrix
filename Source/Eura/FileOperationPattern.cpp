// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationPattern.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileOperationPattern& file_operation_pattern)
    noexcept -> void
    {
        file_operation_pattern.glob = object.at("glob").get<std::string>();
        if(object.contains("matches"))
            file_operation_pattern.matches = object.at("matches").get<FileOperationPatternKind>();
        if(object.contains("options"))
            file_operation_pattern.options = object.at("options").get<FileOperationPatternOptions>(
            );
    }

    auto to_json(nlohmann::json& object, const FileOperationPattern& file_operation_pattern)
    noexcept -> void
    {
        object["glob"] = file_operation_pattern.glob;
        if(file_operation_pattern.matches.has_value())
            object["matches"] = *file_operation_pattern.matches;
        if(file_operation_pattern.options.has_value())
            object["options"] = *file_operation_pattern.options;
    }
}

#endif