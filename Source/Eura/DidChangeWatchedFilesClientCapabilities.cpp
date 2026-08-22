// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DidChangeWatchedFilesClientCapabilities.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DidChangeWatchedFilesClientCapabilities&
    did_change_watched_files_client_capabilities) noexcept -> void
    {
        if(object.contains("dynamicRegistration"))
            did_change_watched_files_client_capabilities.dynamicRegistration = object.at(
            "dynamicRegistration").get<bool>();
        if(object.contains("relativePatternSupport"))
            did_change_watched_files_client_capabilities.relativePatternSupport = object.at(
            "relativePatternSupport").get<bool>();
    }

    auto to_json(nlohmann::json& object, const DidChangeWatchedFilesClientCapabilities&
    did_change_watched_files_client_capabilities) noexcept -> void
    {
        if(did_change_watched_files_client_capabilities.dynamicRegistration.has_value())
            object["dynamicRegistration"] = *did_change_watched_files_client_capabilities.
            dynamicRegistration;
        if(did_change_watched_files_client_capabilities.relativePatternSupport.has_value())
            object["relativePatternSupport"] = *did_change_watched_files_client_capabilities.
            relativePatternSupport;
    }
}

#endif