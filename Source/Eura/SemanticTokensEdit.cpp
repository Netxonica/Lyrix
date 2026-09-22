// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensEdit.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensEdit& semantic_tokens_edit) noexcept
    -> void
    {
        semantic_tokens_edit.start = object.at("start").get<std::uint32_t>();
        semantic_tokens_edit.deleteCount = object.at("deleteCount").get<std::uint32_t>();
        if(object.contains("data"))
        {
            semantic_tokens_edit.data = std::vector<std::uint32_t>{};
            const nlohmann::json& data = object.at("data");
            for(const nlohmann::json& dat : data)
                semantic_tokens_edit.data->emplace_back(dat.get<std::uint32_t>());
        }
    }

    auto to_json(nlohmann::json& object, const SemanticTokensEdit& semantic_tokens_edit) noexcept
    -> void
    {
        object["start"] = semantic_tokens_edit.start;
        object["deleteCount"] = semantic_tokens_edit.deleteCount;
        if(semantic_tokens_edit.data.has_value())
        {
            nlohmann::json data = nlohmann::json::array();
            for(const std::uint32_t dat : *semantic_tokens_edit.data)
                data.emplace_back(dat);
            object["data"] = data;
        }
    }
}

#endif