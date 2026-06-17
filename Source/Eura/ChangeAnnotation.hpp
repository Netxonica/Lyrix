// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_change_annotation
#define lyrix_header_guard_eura_change_annotation
#include "Eura/Any.hpp"

namespace Eura
{
    struct [[nodiscard]] ChangeAnnotation final
    {
        Json::String label;

        std::optional<Json::Boolean> needsConfirmation;

        std::optional<Json::String> description;
    };

    auto Deserialize(const Json::Object& object, ChangeAnnotation& change_annotation) noexcept ->
    void;

    auto Serialize(Json::Object& object, const ChangeAnnotation& change_annotation) noexcept ->
    void;
}

#endif
#endif