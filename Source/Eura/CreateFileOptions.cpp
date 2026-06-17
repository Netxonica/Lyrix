// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CreateFileOptions.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, CreateFileOptions& create_file_options) noexcept
    -> void
    {
        if(object.Contains("overwrite"))
            create_file_options.overwrite = object.Retrieve("overwrite").As<Json::Boolean>();
        if(object.Contains("ignoreIfExists"))
            create_file_options.ignoreIfExists = object.Retrieve("ignoreIfExists").As<Json::Boolean
            >();
    }

    auto Serialize(Json::Object& object, const CreateFileOptions& create_file_options) noexcept ->
    void
    {
        if(create_file_options.overwrite.has_value())
            object.fields.emplace_back("overwrite", *create_file_options.overwrite);
        if(create_file_options.ignoreIfExists.has_value())
            object.fields.emplace_back("ignoreIfExists", *create_file_options.ignoreIfExists);
    }
}

#endif