// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameFileOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RenameFileOptions& rename_file_options) noexcept
    -> void
    {
        if(object.contains("overwrite"))
            rename_file_options.overwrite = object.at("overwrite").get<bool>();
        if(object.contains("ignoreIfExists"))
            rename_file_options.ignoreIfExists = object.at("ignoreIfExists").get<bool>();
    }

    auto to_json(nlohmann::json& object, const RenameFileOptions& rename_file_options) noexcept ->
    void
    {
        if(rename_file_options.overwrite.has_value())
            object["overwrite"] = *rename_file_options.overwrite;
        if(rename_file_options.ignoreIfExists.has_value())
            object["ignoreIfExists"] = *rename_file_options.ignoreIfExists;
    }
}

#endif