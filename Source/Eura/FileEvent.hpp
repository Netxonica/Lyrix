// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_event
#define lyrix_header_guard_eura_file_event
#include "Eura/Json.hpp"
#include "Eura/DocumentUri.hpp"
#include "Eura/FileChangeType.hpp"

namespace Eura
{
    struct [[nodiscard]] FileEvent final
    {
        DocumentUri uri;

        FileChangeType type;
    };

    auto from_json(const nlohmann::json& object, FileEvent& file_event) noexcept -> void;

    auto to_json(nlohmann::json& object, const FileEvent& file_event) noexcept -> void;
}

#endif
#endif