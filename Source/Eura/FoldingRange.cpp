// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FoldingRange.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FoldingRange& folding_range) noexcept -> void
    {
        folding_range.startLine = object.at("startLine").get<std::uint32_t>();
        if(object.contains("startCharacter"))
            folding_range.startCharacter = object.at("startCharacter").get<std::uint32_t>();
        folding_range.endLine = object.at("endLine").get<std::uint32_t>();
        if(object.contains("endCharacter"))
            folding_range.endCharacter = object.at("endCharacter").get<std::uint32_t>();
        if(object.contains("kind"))
            folding_range.kind = object.at("kind").get<FoldingRangeKind>();
        if(object.contains("collapsedText"))
            folding_range.collapsedText = object.at("collapsedText").get<std::string>();
    }

    auto to_json(nlohmann::json& object, const FoldingRange& folding_range) noexcept -> void
    {
        object["startLine"] = folding_range.startLine;
        if(folding_range.startCharacter.has_value())
            object["startCharacter"] = *folding_range.startCharacter;
        object["endLine"] = folding_range.endLine;
        if(folding_range.endCharacter.has_value())
            object["endCharacter"] = *folding_range.endCharacter;
        if(folding_range.kind.has_value())
            object["kind"] = *folding_range.kind;
        if(folding_range.collapsedText.has_value())
            object["collapsedText"] = *folding_range.collapsedText;
    }
}

#endif