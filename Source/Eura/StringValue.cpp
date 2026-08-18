// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/StringValue.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, StringValue& string_value) noexcept -> void
    {
        string_value.kind = object.at("kind").get<std::string>();
        string_value.value = object.at("value").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const StringValue& string_value) noexcept -> void
    {
        object["kind"] = string_value.kind;
        object["value"] = string_value.value;
    }
}

#endif