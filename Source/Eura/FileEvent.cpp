// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FileEvent.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FileEvent& file_event) noexcept -> void
    {
        file_event.uri = object.at("uri").get<DocumentUri>();
        file_event.type = object.at("type").get<FileChangeType>();
    }

    auto to_json(nlohmann::json& object, const FileEvent& file_event) noexcept -> void
    {
        object["uri"] = file_event.uri;
        object["type"] = file_event.type;
    }
}

#endif