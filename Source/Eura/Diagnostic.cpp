// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Diagnostic.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, Diagnostic& diagnostic) noexcept -> void
    {
        diagnostic.range = object.at("range").get<Range>();
        if(object.contains("severity"))
            diagnostic.severity = object.at("severity").get<DiagnosticSeverity>();
        if(object.contains("code"))
        {
            const nlohmann::json& code = object.at("code");
            if(code.is_number_integer())
                diagnostic.code = code.get<std::int32_t>();
            else
                diagnostic.code = code.get<std::string>();
        }
        if(object.contains("codeDescription"))
            diagnostic.codeDescription = object.at("codeDescription").get<CodeDescription>();
        if(object.contains("source"))
            diagnostic.source = object.at("source").get<std::string>();
        const nlohmann::json& message = object.at("message");
        if(message.is_string())
            diagnostic.message = message.get<std::string>();
        else
            diagnostic.message = message.get<MarkupContent>();
        if(object.contains("tags"))
        {
            diagnostic.tags = std::vector<DiagnosticTag>{};
            const nlohmann::json& tags = object.at("tags");
            for(const nlohmann::json& tag : tags)
                diagnostic.tags->emplace_back(static_cast<DiagnosticTag>(tag.get<std::uint8_t>()));
        }
        if(object.contains("relatedInformation"))
        {
            diagnostic.relatedInformation = std::vector<DiagnosticRelatedInformation>{};
            const nlohmann::json& relatedInformations = object.at("relatedInformation");
            for(const nlohmann::json& relatedInformation : relatedInformations)
                diagnostic.relatedInformation->emplace_back(relatedInformation.get<
                DiagnosticRelatedInformation>());
        }
        if(object.contains("data"))
            diagnostic.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const Diagnostic& diagnostic) noexcept -> void
    {
        object["range"] = diagnostic.range;
        if(diagnostic.severity.has_value())
            object["severity"] = *diagnostic.severity;
        if(diagnostic.code.has_value())
            std::visit([&object](auto&& code)
            {
                object["code"] = code;
            }, *diagnostic.code);
        if(diagnostic.codeDescription.has_value())
            object["codeDescription"] = *diagnostic.codeDescription;
        if(diagnostic.source.has_value())
            object["source"] = *diagnostic.source;
        std::visit([&object](auto&& message)
        {
            object["message"] = message;
        }, diagnostic.message);
        if(diagnostic.tags.has_value())
        {
            nlohmann::json tags = nlohmann::json::array();
            for(const DiagnosticTag tag : *diagnostic.tags)
                tags.emplace_back(static_cast<std::uint8_t>(tag));
            object["tags"] = tags;
        }
        if(diagnostic.relatedInformation.has_value())
        {
            nlohmann::json relatedInformations = nlohmann::json::array();
            for(const DiagnosticRelatedInformation& relatedInformation : *diagnostic.
            relatedInformation)
                relatedInformations.emplace_back(relatedInformation);
            object["relatedInformation"] = relatedInformations;
        }
        if(diagnostic.data.has_value())
            object["data"] = *diagnostic.data;
    }
}

#endif