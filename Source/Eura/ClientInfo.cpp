// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ClientInfo.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ClientInfo& client_info) noexcept -> void
    {
        client_info.name = object.at("name").get<std::string>();
        if(object.contains("version"))
            client_info.version = object.at("version").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const ClientInfo& client_info) noexcept -> void
    {
        object["name"] = client_info.name;
        if(client_info.version.has_value())
            object["version"] = *client_info.version;
    }
}

#endif