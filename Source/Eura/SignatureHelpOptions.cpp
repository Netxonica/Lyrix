// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelpOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SignatureHelpOptions& signature_help_options)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressOptions&>(signature_help_options));
        if(object.contains("triggerCharacters"))
        {
            signature_help_options.triggerCharacters = std::vector<std::string>{};
            const nlohmann::json& triggerCharacters = object.at("triggerCharacters");
            for(const nlohmann::json& triggerCharacter : triggerCharacters)
                signature_help_options.triggerCharacters->emplace_back(triggerCharacter.get<std::
                string>());
        }
        if(object.contains("retriggerCharacters"))
        {
            signature_help_options.retriggerCharacters = std::vector<std::string>{};
            const nlohmann::json& retriggerCharacters = object.at("retriggerCharacters");
            for(const nlohmann::json& retriggerCharacter : retriggerCharacters)
                signature_help_options.retriggerCharacters->emplace_back(retriggerCharacter.get<std
                ::string>());
        }
    }

    auto to_json(nlohmann::json& object, const SignatureHelpOptions& signature_help_options)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressOptions&>(signature_help_options));
        if(signature_help_options.triggerCharacters.has_value())
        {
            nlohmann::json triggerCharacters = nlohmann::json::array();
            for(const std::string& triggerCharacter : *signature_help_options.triggerCharacters)
                triggerCharacters.emplace_back(triggerCharacter);
            object["triggerCharacters"] = triggerCharacters;
        }
        if(signature_help_options.retriggerCharacters.has_value())
        {
            nlohmann::json retriggerCharacters = nlohmann::json::array();
            for(const std::string& retriggerCharacter : *signature_help_options.retriggerCharacters
            )
                retriggerCharacters.emplace_back(retriggerCharacter);
            object["retriggerCharacters"] = retriggerCharacters;
        }
    }
}

#endif