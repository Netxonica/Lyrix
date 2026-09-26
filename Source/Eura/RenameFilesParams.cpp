// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/RenameFilesParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, RenameFilesParams& rename_files_params) noexcept
    -> void
    {
        const nlohmann::json& files = object.at("files");
        for(const nlohmann::json& file : files)
            rename_files_params.files.emplace_back(file.get<FileRename>());
    }

    auto to_json(nlohmann::json& object, const RenameFilesParams& rename_files_params) noexcept ->
    void
    {
        nlohmann::json files = nlohmann::json::array();
        for(const FileRename& file : rename_files_params.files)
            files.emplace_back(file);
        object["files"] = files;
    }
}

#endif