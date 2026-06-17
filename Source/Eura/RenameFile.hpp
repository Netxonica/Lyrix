// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_rename_file
#define lyrix_header_guard_eura_rename_file
#include "Eura/DocumentUri.hpp"
#include "Eura/RenameFileOptions.hpp"
#include "Eura/ChangeAnnotationIdentifier.hpp"

namespace Eura
{
    struct [[nodiscard]] RenameFile final
    {
        Json::String kind;

        DocumentUri oldUri, newUri;

        std::optional<RenameFileOptions> options;

        std::optional<ChangeAnnotationIdentifier> annotationId;
    };

    auto Deserialize(const Json::Object& object, RenameFile& rename_file) noexcept -> void;

    auto Serialize(Json::Object& object, const RenameFile& rename_file) noexcept -> void;
}

#endif
#endif