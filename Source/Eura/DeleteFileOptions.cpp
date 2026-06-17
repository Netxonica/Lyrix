// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeleteFileOptions.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, DeleteFileOptions& delete_file_options) noexcept
    -> void
    {
        if(object.Contains("recursive"))
            delete_file_options.recursive = object.Retrieve("recursive").As<Json::Boolean>();
        if(object.Contains("ignoreIfNotExists"))
            delete_file_options.ignoreIfNotExists = object.Retrieve("ignoreIfNotExists").As<Json::
            Boolean>();
    }

    auto Serialize(Json::Object& object, const DeleteFileOptions& delete_file_options) noexcept ->
    void
    {
        if(delete_file_options.recursive.has_value())
            object.fields.emplace_back("recursive", *delete_file_options.recursive);
        if(delete_file_options.ignoreIfNotExists.has_value())
            object.fields.emplace_back("ignoreIfNotExists", *delete_file_options.ignoreIfNotExists)
            ;
    }
}

#endif