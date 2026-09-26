// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileCreate.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileCreate& file_create) noexcept -> void
    {
        file_create.uri = object.at("uri").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const FileCreate& file_create) noexcept -> void
    {
        object["uri"] = file_create.uri;
    }
}

#endif