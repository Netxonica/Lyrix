// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_delete_files_params
#define lyrix_header_guard_eura_delete_files_params
#include "Eura/FileDelete.hpp"

namespace Eura
{
    struct [[nodiscard]] DeleteFilesParams final
    {
        std::vector<FileDelete> files;
    };

    auto from_json(const nlohmann::json& object, DeleteFilesParams& delete_files_params) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const DeleteFilesParams& delete_files_params) noexcept ->
    void;
}

#endif
#endif