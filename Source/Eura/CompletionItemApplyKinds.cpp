// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionItemApplyKinds.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionItemApplyKinds&
    completion_item_apply_kinds) noexcept -> void
    {
        if(object.contains("commitCharacters"))
            completion_item_apply_kinds.commitCharacters = object.at("commitCharacters").get<
            ApplyKind>();
        if(object.contains("data"))
            completion_item_apply_kinds.data = object.at("data").get<ApplyKind>();
    }

    auto to_json(nlohmann::json& object, const CompletionItemApplyKinds&
    completion_item_apply_kinds) noexcept -> void
    {
        if(completion_item_apply_kinds.commitCharacters.has_value())
            object["commitCharacters"] = *completion_item_apply_kinds.commitCharacters;
        if(completion_item_apply_kinds.data.has_value())
            object["data"] = *completion_item_apply_kinds.data;
    }
}

#endif