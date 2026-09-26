// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileDelete.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileDelete& file_delete) noexcept -> void
    {
        file_delete.uri = object.at("uri").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const FileDelete& file_delete) noexcept -> void
    {
        object["uri"] = file_delete.uri;
    }
}

#endif