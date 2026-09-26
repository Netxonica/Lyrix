// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_create_files_params
#define lyrix_header_guard_eura_create_files_params
#include "Eura/FileCreate.hpp"

namespace Eura
{
    struct [[nodiscard]] CreateFilesParams final
    {
        std::vector<FileCreate> files;
    };

    auto from_json(const nlohmann::json& object, CreateFilesParams& create_files_params) noexcept
    -> void;

    auto to_json(nlohmann::json& object, const CreateFilesParams& create_files_params) noexcept ->
    void;
}

#endif
#endif