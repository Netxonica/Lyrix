// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InitializeResult.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InitializeResult& initialize_result) noexcept ->
    void
    {
        initialize_result.capabilities = object.at("capabilities").get<ServerCapabilities>();
        if(object.contains("serverInfo"))
            initialize_result.serverInfo = object.at("serverInfo").get<ServerInfo>();
    }

    auto to_json(nlohmann::json& object, const InitializeResult& initialize_result) noexcept ->
    void
    {
        object["capabilities"] = initialize_result.capabilities;
        if(initialize_result.serverInfo.has_value())
            object["serverInfo"] = *initialize_result.serverInfo;
    }
}

#endif