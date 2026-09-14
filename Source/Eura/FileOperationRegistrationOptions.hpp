// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_operation_registration_options
#define lyrix_header_guard_eura_file_operation_registration_options
#include "Eura/FileOperationFilter.hpp"

namespace Eura
{
    struct [[nodiscard]] FileOperationRegistrationOptions final
    {
        std::vector<FileOperationFilter> filters;
    };

    auto from_json(const nlohmann::json& object, FileOperationRegistrationOptions&
    file_operation_registration_options) noexcept -> void;

    auto to_json(nlohmann::json& object, const FileOperationRegistrationOptions&
    file_operation_registration_options) noexcept -> void;
}

#endif
#endif