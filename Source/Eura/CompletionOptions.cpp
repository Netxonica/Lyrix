// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionOptions& completion_options) noexcept ->
    void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(completion_options));
        if(object.contains("triggerCharacters"))
        {
            completion_options.triggerCharacters = std::vector<std::string>{};
            const nlohmann::json& triggerCharacters = object.at("triggerCharacters");
            for(const nlohmann::json& triggerCharacter : triggerCharacters)
                completion_options.triggerCharacters->emplace_back(triggerCharacter.get<std::string
                >());
        }
        if(object.contains("allCommitCharacters"))
        {
            completion_options.allCommitCharacters = std::vector<std::string>{};
            const nlohmann::json& allCommitCharacters = object.at("allCommitCharacters");
            for(const nlohmann::json& allCommitCharacter : allCommitCharacters)
                completion_options.allCommitCharacters->emplace_back(allCommitCharacter.get<std::
                string>());
        }
        if(object.contains("resolveProvider"))
            completion_options.resolveProvider = object.at("resolveProvider").get<bool>();
        if(object.contains("completionItem"))
            completion_options.completionItem = object.at("completionItem").get<
            ServerCompletionItemOptions>();
    }

    auto to_json(nlohmann::json& object, const CompletionOptions& completion_options) noexcept ->
    void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(completion_options));
        if(completion_options.triggerCharacters.has_value())
        {
            nlohmann::json triggerCharacters = nlohmann::json::array();
            for(const std::string& triggerCharacter : *completion_options.triggerCharacters)
                triggerCharacters.emplace_back(triggerCharacter);
            object["triggerCharacters"] = triggerCharacters;
        }
        if(completion_options.allCommitCharacters.has_value())
        {
            nlohmann::json allCommitCharacters = nlohmann::json::array();
            for(const std::string& allCommitCharacter : *completion_options.allCommitCharacters)
                allCommitCharacters.emplace_back(allCommitCharacter);
            object["allCommitCharacters"] = allCommitCharacters;
        }
        if(completion_options.resolveProvider.has_value())
            object["resolveProvider"] = *completion_options.resolveProvider;
        if(completion_options.completionItem.has_value())
            object["completionItem"] = *completion_options.completionItem;
    }
}

#endif