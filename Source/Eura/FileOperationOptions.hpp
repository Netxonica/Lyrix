// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_operation_options
#define lyrix_header_guard_eura_file_operation_options
#include "Eura/FileOperationRegistrationOptions.hpp"

namespace Eura
{
    struct [[nodiscard]] FileOperationOptions final
    {
        std::optional<FileOperationRegistrationOptions> didCreate, willCreate, didRename,
        willRename, didDelete, willDelete;
    };

    auto from_json(const nlohmann::json& object, FileOperationOptions& file_operation_options)
    noexcept -> void;

    auto to_json(nlohmann::json& object, const FileOperationOptions& file_operation_options)
    noexcept -> void;
}

#endif
#endif