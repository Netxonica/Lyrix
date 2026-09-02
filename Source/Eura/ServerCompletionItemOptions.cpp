// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/ServerCompletionItemOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, ServerCompletionItemOptions&
    server_completion_item_options) noexcept -> void
    {
        if(object.contains("labelDetailsSupport"))
            server_completion_item_options.labelDetailsSupport = object.at("labelDetailsSupport").
            get<bool>();
    }

    auto to_json(nlohmann::json& object, const ServerCompletionItemOptions&
    server_completion_item_options) noexcept -> void
    {
        if(server_completion_item_options.labelDetailsSupport.has_value())
            object["labelDetailsSupport"] = *server_completion_item_options.labelDetailsSupport;
    }
}

#endif