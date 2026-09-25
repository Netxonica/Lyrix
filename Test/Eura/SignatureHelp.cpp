// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelp.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"signatures\":[{\"label\":\"meow\",\"documentation\":\"meow nya\",\"parameters\":[{\"label\":[42,67],\"documentation\":\"meow nya\"}],\"activeParameter\":null}],\"activeSignature\":67,\"activeParameter\":null}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SignatureHelp request;
    Eura::from_json(root, request);
    if(request.signatures.size() not_eq 1uz or request.signatures[0uz].label not_eq "meow" or not
    request.signatures[0uz].documentation.has_value() or not std::holds_alternative<std::string>(*
    request.signatures[0uz].documentation) or std::get<std::string>(*request.signatures[0uz].
    documentation) not_eq "meow nya" or not request.signatures[0uz].parameters.has_value() or
    request.signatures[0uz].parameters->size() not_eq 1uz)
        return false;
    const Eura::ParameterInformation& parameter = (*request.signatures[0uz].parameters)[0uz];
    if(not std::holds_alternative<std::array<std::uint32_t, 2uz>>(parameter.label))
        return false;
    const std::array<std::uint32_t, 2uz> label = std::get<std::array<std::uint32_t, 2uz>>(parameter
    .label);
    if(label[0uz] not_eq 42u or label[1uz] not_eq 67u or not parameter.documentation.has_value() or
    not std::holds_alternative<std::string>(*parameter.documentation) or std::get<std::string>(*
    parameter.documentation) not_eq "meow nya" or not request.signatures[0uz].activeParameter.
    has_value() or not std::holds_alternative<std::nullptr_t>(*request.signatures[0uz].
    activeParameter) or not request.activeSignature.has_value() or *request.activeSignature not_eq
    67u or not request.activeParameter.has_value() or not std::holds_alternative<std::nullptr_t>(*
    request.activeParameter))
        return false;
    nlohmann::json response;
    Eura::to_json(response, request);
    return response.dump() == root.dump();
}

int main()
{
    return not lyrix_test();
}

#endif