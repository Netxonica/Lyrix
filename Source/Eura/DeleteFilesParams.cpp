// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DeleteFilesParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DeleteFilesParams& delete_files_params) noexcept
    -> void
    {
        const nlohmann::json& files = object.at("files");
        for(const nlohmann::json& file : files)
            delete_files_params.files.emplace_back(file.get<FileDelete>());
    }

    auto to_json(nlohmann::json& object, const DeleteFilesParams& delete_files_params) noexcept ->
    void
    {
        nlohmann::json files = nlohmann::json::array();
        for(const FileDelete& file : delete_files_params.files)
            files.emplace_back(file);
        object["files"] = files;
    }
}

#endif