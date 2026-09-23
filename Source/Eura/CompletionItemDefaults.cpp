// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionItemDefaults.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionItemDefaults& completion_item_defaults)
    noexcept -> void
    {
        if(object.contains("commitCharacters"))
        {
            completion_item_defaults.commitCharacters = std::vector<std::string>{};
            const nlohmann::json& commitCharacters = object.at("commitCharacters");
            for(const nlohmann::json& commitCharacter : commitCharacters)
                completion_item_defaults.commitCharacters->emplace_back(commitCharacter.get<std::
                string>());
        }
        if(object.contains("editRange"))
        {
            const nlohmann::json& editRange = object.at("editRange");
            if(editRange.contains("insert"))
                completion_item_defaults.editRange = editRange.get<EditRangeWithInsertReplace>();
            else
                completion_item_defaults.editRange = editRange.get<Range>();
        }
        if(object.contains("insertTextFormat"))
            completion_item_defaults.insertTextFormat = object.at("insertTextFormat").get<
            InsertTextFormat>();
        if(object.contains("insertTextMode"))
            completion_item_defaults.insertTextMode = object.at("insertTextMode").get<
            InsertTextMode>();
        if(object.contains("data"))
            completion_item_defaults.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const CompletionItemDefaults& completion_item_defaults)
    noexcept -> void
    {
        if(completion_item_defaults.commitCharacters.has_value())
        {
            nlohmann::json commitCharacters = nlohmann::json::array();
            for(const std::string& commitCharacter : *completion_item_defaults.commitCharacters)
                commitCharacters.emplace_back(commitCharacter);
            object["commitCharacters"] = commitCharacters;
        }
        if(completion_item_defaults.editRange.has_value())
            std::visit([&object](auto&& editRange)
            {
                object["editRange"] = editRange;
            }, *completion_item_defaults.editRange);
        if(completion_item_defaults.insertTextFormat.has_value())
            object["insertTextFormat"] = *completion_item_defaults.insertTextFormat;
        if(completion_item_defaults.insertTextMode.has_value())
            object["insertTextMode"] = *completion_item_defaults.insertTextMode;
        if(completion_item_defaults.data.has_value())
            object["data"] = *completion_item_defaults.data;
    }
}

#endif