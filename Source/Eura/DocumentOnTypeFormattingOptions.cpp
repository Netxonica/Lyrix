// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/DocumentOnTypeFormattingOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, DocumentOnTypeFormattingOptions&
    document_on_type_formatting_options) noexcept -> void
    {
        document_on_type_formatting_options.firstTriggerCharacter = object.at(
        "firstTriggerCharacter").get<std::string>();
        if(object.contains("moreTriggerCharacter"))
        {
            document_on_type_formatting_options.moreTriggerCharacter = std::vector<std::string>{};
            const nlohmann::json& moreTriggerCharacter = object.at("moreTriggerCharacter");
            for(const nlohmann::json& more : moreTriggerCharacter)
                document_on_type_formatting_options.moreTriggerCharacter->emplace_back(more.get<std
                ::string>());
        }
    }

    auto to_json(nlohmann::json& object, const DocumentOnTypeFormattingOptions&
    document_on_type_formatting_options) noexcept -> void
    {
        object["firstTriggerCharacter"] = document_on_type_formatting_options.firstTriggerCharacter
        ;
        if(document_on_type_formatting_options.moreTriggerCharacter.has_value())
        {
            nlohmann::json moreTriggerCharacter = nlohmann::json::array();
            for(const std::string& more : *document_on_type_formatting_options.moreTriggerCharacter
            )
                moreTriggerCharacter.emplace_back(more);
            object["moreTriggerCharacter"] = moreTriggerCharacter;
        }
    }
}

#endif