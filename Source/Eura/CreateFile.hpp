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
        Json::String kind;

        DocumentUri uri;

        std::optional<CreateFileOptions> options;

        std::optional<ChangeAnnotationIdentifier> annotationId;
    };

    auto Deserialize(const Json::Object& object, CreateFile& create_file) noexcept -> void;

    auto Serialize(Json::Object& object, const CreateFile& create_file) noexcept -> void;
}

#endif
#endif