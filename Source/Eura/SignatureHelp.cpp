// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelp.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SignatureHelp& signature_help) noexcept -> void
    {
        const nlohmann::json& signatures = object.at("signatures");
        for(const nlohmann::json& signature : signatures)
            signature_help.signatures.emplace_back(signature.get<SignatureInformation>());
        if(object.contains("activeSignature"))
            signature_help.activeSignature = object.at("activeSignature").get<std::uint32_t>();
        if(object.contains("activeParameter"))
        {
            const nlohmann::json& activeParameter = object.at("activeParameter");
            if(activeParameter.is_number_unsigned())
                signature_help.activeParameter = activeParameter.get<std::uint32_t>();
            else
                signature_help.activeParameter = nullptr;
        }
    }

    auto to_json(nlohmann::json& object, const SignatureHelp& signature_help) noexcept -> void
    {
        nlohmann::json signatures = nlohmann::json::array();
        for(const SignatureInformation& signature : signature_help.signatures)
            signatures.emplace_back(signature);
        object["signatures"] = signatures;
        if(signature_help.activeSignature.has_value())
            object["activeSignature"] = *signature_help.activeSignature;
        if(signature_help.activeParameter.has_value())
            std::visit([&object](auto&& activeParameter)
            {
                object["activeParameter"] = activeParameter;
            }, *signature_help.activeParameter);
    }
}

#endif