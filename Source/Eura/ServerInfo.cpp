// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ServerInfo.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ServerInfo& server_info) noexcept -> void
    {
        server_info.name = object.at("name").get<std::string>();
        if(object.contains("version"))
            server_info.version = object.at("version").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const ServerInfo& server_info) noexcept -> void
    {
        object["name"] = server_info.name;
        if(server_info.version.has_value())
            object["version"] = *server_info.version;
    }
}

#endif