// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeleteFileOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DeleteFileOptions& delete_file_options) noexcept
    -> void
    {
        if(object.contains("recursive"))
            delete_file_options.recursive = object.at("recursive").get<bool>();
        if(object.contains("ignoreIfNotExists"))
            delete_file_options.ignoreIfNotExists = object.at("ignoreIfNotExists").get<bool>();
    }

    auto to_json(nlohmann::json& object, const DeleteFileOptions& delete_file_options) noexcept ->
    void
    {
        if(delete_file_options.recursive.has_value())
            object["recursive"] = *delete_file_options.recursive;
        if(delete_file_options.ignoreIfNotExists.has_value())
            object["ignoreIfNotExists"] = *delete_file_options.ignoreIfNotExists;
    }
}

#endif