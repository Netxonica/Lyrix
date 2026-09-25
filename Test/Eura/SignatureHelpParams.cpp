// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SignatureHelpParams.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"textDocument\":{\"uri\":\"meow.extension\"},\"position\":{\"line\":42,\"character\":67},\"workDoneToken\":\"meow\",\"context\":{\"triggerKind\":3,\"triggerCharacter\":\"meow\",\"isRetrigger\":true,\"activeSignatureHelp\":{\"signatures\":[{\"label\":\"meow\",\"documentation\":\"meow nya\",\"parameters\":[{\"label\":[42,67],\"documentation\":\"meow nya\"}],\"activeParameter\":null}],\"activeSignature\":67,\"activeParameter\":null}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::SignatureHelpParams request;
    Eura::from_json(root, request);
    if(request.textDocument.uri not_eq "meow.extension" or request.position.line not_eq 42u or
    request.position.character not_eq 67u or not request.workDoneToken.has_value() or not std::
    holds_alternative<std::string>(*request.workDoneToken) or std::get<std::string>(*request.
    workDoneToken) not_eq "meow" or not request.context.has_value() or request.context->triggerKind
    not_eq Eura::SignatureHelpTriggerKind::ContentChange or not request.context->triggerCharacter.
    has_value() or *request.context->triggerCharacter not_eq "meow" or not request.context->
    isRetrigger or not request.context->activeSignatureHelp.has_value() or request.context->
    activeSignatureHelp->signatures.size() not_eq 1uz or request.context->activeSignatureHelp->
    signatures[0uz].label not_eq "meow" or not request.context->activeSignatureHelp->signatures[0uz
    ].documentation.has_value() or not std::holds_alternative<std::string>(*request.context->
    activeSignatureHelp->signatures[0uz].documentation) or std::get<std::string>(*request.context->
    activeSignatureHelp->signatures[0uz].documentation) not_eq "meow nya" or not request.context->
    activeSignatureHelp->signatures[0uz].parameters.has_value() or request.context->
    activeSignatureHelp->signatures[0uz].parameters->size() not_eq 1uz)
        return false;
    const Eura::ParameterInformation& parameter = (*request.context->activeSignatureHelp->
    signatures[0uz].parameters)[0uz];
    if(not std::holds_alternative<std::array<std::uint32_t, 2uz>>(parameter.label))
        return false;
    const std::array<std::uint32_t, 2uz> label = std::get<std::array<std::uint32_t, 2uz>>(parameter
    .label);
    if(label[0uz] not_eq 42u or label[1uz] not_eq 67u or not parameter.documentation.has_value() or
    not std::holds_alternative<std::string>(*parameter.documentation) or std::get<std::string>(*
    parameter.documentation) not_eq "meow nya" or not request.context->activeSignatureHelp->
    signatures[0uz].activeParameter.has_value() or not std::holds_alternative<std::nullptr_t>(*
    request.context->activeSignatureHelp->signatures[0uz].activeParameter) or not request.context->
    activeSignatureHelp->activeSignature.has_value() or *request.context->activeSignatureHelp->
    activeSignature not_eq 67u or not request.context->activeSignatureHelp->activeParameter.
    has_value() or not std::holds_alternative<std::nullptr_t>(*request.context->activeSignatureHelp
    ->activeParameter))
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