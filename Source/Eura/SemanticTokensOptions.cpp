// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SemanticTokensOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SemanticTokensOptions& semantic_tokens_options)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(semantic_tokens_options));
        semantic_tokens_options.legend = object.at("legend").get<SemanticTokensLegend>();
        if(object.contains("range"))
        {
            const nlohmann::json& range = object.at("range");
            if(range.is_boolean())
                semantic_tokens_options.range = range.get<bool>();
            else
                semantic_tokens_options.range = Empty{};
        }
        if(object.contains("full"))
        {
            const nlohmann::json& full = object.at("full");
            if(full.is_boolean())
                semantic_tokens_options.full = full.get<bool>();
            else
                semantic_tokens_options.full = full.get<SemanticTokensFullDelta>();
        }
    }

    auto to_json(nlohmann::json& object, const SemanticTokensOptions& semantic_tokens_options)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(semantic_tokens_options));
        object["legend"] = semantic_tokens_options.legend;
        if(semantic_tokens_options.range.has_value())
            std::visit([&object](auto&& range)
            {
                object["range"] = range;
            }, *semantic_tokens_options.range);
        if(semantic_tokens_options.full.has_value())
            std::visit([&object](auto&& full)
            {
                object["full"] = full;
            }, *semantic_tokens_options.full);
    }
}

#endif