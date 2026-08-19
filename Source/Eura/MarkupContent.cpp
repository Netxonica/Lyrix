// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/MarkupContent.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, MarkupContent& markup_content) noexcept -> void
    {
        markup_content.kind = object.at("kind").get<MarkupKind>();
        markup_content.value = object.at("value").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const MarkupContent& markup_content) noexcept -> void
    {
        object["kind"] = markup_content.kind;
        object["value"] = markup_content.value;
    }
}

#endif