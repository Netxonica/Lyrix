// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileRename.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileRename& file_rename) noexcept -> void
    {
        file_rename.oldUri = object.at("oldUri").get<std::string>();
        file_rename.newUri = object.at("newUri").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const FileRename& file_rename) noexcept -> void
    {
        object["oldUri"] = file_rename.oldUri;
        object["newUri"] = file_rename.newUri;
    }
}

#endif