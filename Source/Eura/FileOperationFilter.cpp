// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationFilter.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileOperationFilter& file_operation_filter)
    noexcept -> void
    {
        if(object.contains("scheme"))
            file_operation_filter.scheme = object.at("scheme").get<std::string>();
        file_operation_filter.pattern = object.at("pattern").get<FileOperationPattern>();
    }

    auto to_json(nlohmann::json& object, const FileOperationFilter& file_operation_filter) noexcept
    -> void
    {
        if(file_operation_filter.scheme.has_value())
            object["scheme"] = *file_operation_filter.scheme;
        object["pattern"] = file_operation_filter.pattern;
    }
}

#endif