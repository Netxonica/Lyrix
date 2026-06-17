// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameFileOptions.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, RenameFileOptions& rename_file_options) noexcept
    -> void
    {
        if(object.Contains("overwrite"))
            rename_file_options.overwrite = object.Retrieve("overwrite").As<Json::Boolean>();
        if(object.Contains("ignoreIfExists"))
            rename_file_options.ignoreIfExists = object.Retrieve("ignoreIfExists").As<Json::Boolean
            >();
    }

    auto Serialize(Json::Object& object, const RenameFileOptions& rename_file_options) noexcept ->
    void
    {
        if(rename_file_options.overwrite.has_value())
            object.fields.emplace_back("overwrite", *rename_file_options.overwrite);
        if(rename_file_options.ignoreIfExists.has_value())
            object.fields.emplace_back("ignoreIfExists", *rename_file_options.ignoreIfExists);
    }
}

#endif