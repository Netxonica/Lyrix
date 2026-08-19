// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_create_file
#define lyrix_header_guard_eura_create_file
#include "Eura/DocumentUri.hpp"
#include "Eura/CreateFileOptions.hpp"
#include "Eura/ChangeAnnotationIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] CreateFile final
    {
        std::string kind;

        DocumentUri uri;

        std::optional<CreateFileOptions> options;

        std::optional<ChangeAnnotationIdentifier> annotationId;
    };

    auto from_json(const nlohmann::json& object, CreateFile& create_file) noexcept -> void;

    auto to_json(nlohmann::json& object, const CreateFile& create_file) noexcept -> void;
}

#endif
#endif