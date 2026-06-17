// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_delete_file_options
#define lyrix_header_guard_eura_delete_file_options
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] DeleteFileOptions final
    {
        std::optional<Json::Boolean> recursive, ignoreIfNotExists;
    };

    auto Deserialize(const Json::Object& object, DeleteFileOptions& delete_file_options) noexcept
    -> void;

    auto Serialize(Json::Object& object, const DeleteFileOptions& delete_file_options) noexcept ->
    void;
}

#endif
#endif