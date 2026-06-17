// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Diagnostic.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, Diagnostic& diagnostic) noexcept -> void
    {
        Deserialize(object.Retrieve("range").As<Json::Object>(), diagnostic.range);
        if(object.Contains("severity"))
            diagnostic.severity = object.Retrieve("severity").As<Json::Uinteger>();
        if(object.Contains("code"))
        {
            const Json::Any& code = object.Retrieve("code");
            if(code.IsUinteger())
                diagnostic.code = static_cast<Json::Integer>(code.As<Json::Uinteger>());
            else if(code.IsInteger())
                diagnostic.code = code.As<Json::Integer>();
            else if(code.IsString())
                diagnostic.code = code.As<Json::String>();
            else
                std::abort();
        }
        if(object.Contains("codeDescription"))
        {
            CodeDescription codeDescription;
            Deserialize(object.Retrieve("codeDescription").As<Json::Object>(), codeDescription);
            diagnostic.codeDescription = codeDescription;
        }
        if(object.Contains("source"))
            diagnostic.source = object.Retrieve("source").As<Json::String>();
        const Json::Any& message = object.Retrieve("message");
        if(message.IsString())
            diagnostic.message = message.As<Json::String>();
        else if(message.IsObject())
        {
            MarkupContent markup_content;
            Deserialize(message.As<Json::Object>(), markup_content);
            diagnostic.message = markup_content;
        }
        else
            std::abort();
        if(object.Contains("tags"))
        {
            const Json::Array& tags = object.Retrieve("tags").As<Json::Array>();
            for(const Json::Any& tag : tags)
                diagnostic.tags->emplace_back(tag.As<DiagnosticTag>());
        }
        if(object.Contains("relatedInformation"))
        {
            diagnostic.relatedInformation = std::vector<DiagnosticRelatedInformation>{};
            const Json::Array& relatedInformation = object.Retrieve("relatedInformation").As<Json::
            Array>();
            for(const Json::Any& relatedInfo : relatedInformation)
            {
                DiagnosticRelatedInformation diagnostic_related_information;
                Deserialize(relatedInfo.As<Json::Object>(), diagnostic_related_information);
                diagnostic.relatedInformation->emplace_back(diagnostic_related_information);
            }
        }
        if(object.Contains("data"))
            diagnostic.data = std::move(object.Retrieve("data"));
    }

    auto Serialize(Json::Object& object, const Diagnostic& diagnostic) noexcept -> void
    {
        Serialize(object.NestedObject("range"), diagnostic.range);
        if(diagnostic.severity.has_value())
            object.fields.emplace_back("severity", *diagnostic.severity);
        if(diagnostic.code.has_value())
            std::visit([&object](auto&& code)
            {
                object.fields.emplace_back("code", code);
            }, *diagnostic.code);
        if(diagnostic.codeDescription.has_value())
            Serialize(object.NestedObject("codeDescription"), *diagnostic.codeDescription);
        if(diagnostic.source.has_value())
            object.fields.emplace_back("source", *diagnostic.source);
        if(std::holds_alternative<Json::String>(diagnostic.message))
            object.fields.emplace_back("message", std::get<Json::String>(diagnostic.message));
        else
            Serialize(object.NestedObject("message"), std::get<MarkupContent>(diagnostic.message));
        if(diagnostic.tags.has_value())
        {
            Json::Array& tags = object.NestedArray("tags");
            for(const DiagnosticTag tag : *diagnostic.tags)
                tags.emplace_back(tag);
        }
        if(diagnostic.relatedInformation.has_value())
        {
            Json::Array& relatedInformation = object.NestedArray("relatedInformation");
            for(const DiagnosticRelatedInformation& relatedInfo : *diagnostic.relatedInformation)
            {
                Json::Object related;
                Serialize(related, relatedInfo);
                relatedInformation.emplace_back(std::move(related));
            }
        }
        if(diagnostic.data.has_value())
            std::visit([&object](auto&& data)
            {
                object.fields.emplace_back("data", std::move(data));
            }, *diagnostic.data);
    }
}

#endif