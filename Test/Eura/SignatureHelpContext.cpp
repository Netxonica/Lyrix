// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelpContext.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"triggerKind\":3,\"triggerCharacter\":\"meow\",\"isRetrigger\":true,\"activeSignatureHelp\":{\"signatures\":[{\"label\":\"meow\",\"documentation\":\"meow nya\",\"parameters\":[{\"label\":[42,67],\"documentation\":\"meow nya\"}],\"activeParameter\":null}],\"activeSignature\":67,\"activeParameter\":null}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SignatureHelpContext request;
    Eura::from_json(root, request);
    if(request.triggerKind not_eq Eura::SignatureHelpTriggerKind::ContentChange or not request.
    triggerCharacter.has_value() or *request.triggerCharacter not_eq "meow" or not request.
    isRetrigger or not request.activeSignatureHelp.has_value() or request.activeSignatureHelp->
    signatures.size() not_eq 1uz or request.activeSignatureHelp->signatures[0uz].label not_eq
    "meow" or not request.activeSignatureHelp->signatures[0uz].documentation.has_value() or not std
    ::holds_alternative<std::string>(*request.activeSignatureHelp->signatures[0uz].documentation)
    or std::get<std::string>(*request.activeSignatureHelp->signatures[0uz].documentation) not_eq
    "meow nya" or not request.activeSignatureHelp->signatures[0uz].parameters.has_value() or
    request.activeSignatureHelp->signatures[0uz].parameters->size() not_eq 1uz)
        return false;
    const Eura::ParameterInformation& parameter = (*request.activeSignatureHelp->signatures[0uz].
    parameters)[0uz];
    if(not std::holds_alternative<std::array<std::uint32_t, 2uz>>(parameter.label))
        return false;
    const std::array<std::uint32_t, 2uz> label = std::get<std::array<std::uint32_t, 2uz>>(parameter
    .label);
    if(label[0uz] not_eq 42u or label[1uz] not_eq 67u or not parameter.documentation.has_value() or
    not std::holds_alternative<std::string>(*parameter.documentation) or std::get<std::string>(*
    parameter.documentation) not_eq "meow nya" or not request.activeSignatureHelp->signatures[0uz].
    activeParameter.has_value() or not std::holds_alternative<std::nullptr_t>(*request.
    activeSignatureHelp->signatures[0uz].activeParameter) or not request.activeSignatureHelp->
    activeSignature.has_value() or *request.activeSignatureHelp->activeSignature not_eq 67u or not
    request.activeSignatureHelp->activeParameter.has_value() or not std::holds_alternative<std::
    nullptr_t>(*request.activeSignatureHelp->activeParameter))
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