// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileOperationRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileOperationRegistrationOptions&
    file_operation_registration_options) noexcept -> void
    {
        const nlohmann::json& filters = object.at("filters");
        for(const nlohmann::json& filter : filters)
            file_operation_registration_options.filters.emplace_back(filter.get<FileOperationFilter
            >());
    }

    auto to_json(nlohmann::json& object, const FileOperationRegistrationOptions&
    file_operation_registration_options) noexcept -> void
    {
        nlohmann::json filters = nlohmann::json::array();
        for(const FileOperationFilter& filter : file_operation_registration_options.filters)
            filters.emplace_back(filter);
        object["filters"] = filters;
    }
}

#endif