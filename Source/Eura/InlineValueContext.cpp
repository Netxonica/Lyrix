// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineValueContext.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, InlineValueContext& inline_value_context) noexcept
    -> void
    {
        inline_value_context.frameId = object.at("frameId").get<std::int32_t>();
        inline_value_context.stoppedLocation = object.at("stoppedLocation").get<Range>();
    }

    auto to_json(nlohmann::json& object, const InlineValueContext& inline_value_context) noexcept
    -> void
    {
        object["frameId"] = inline_value_context.frameId;
        object["stoppedLocation"] = inline_value_context.stoppedLocation;
    }
}

#endif