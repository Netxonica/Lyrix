// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/CodeActionOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneProgress\":true,\"codeActionKinds\":[\"quickfix\"],\"documentation\":[{\"kind\":\"quickfix\",\"command\":{\"title\":\"meow\",\"tooltip\":\"nya\",\"command\":\"operation:cute\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]}}],\"resolveProvider\":true}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CodeActionOptions request;
    Eura::from_json(root, request);
    if(not request.workDoneProgress.has_value() or not *request.workDoneProgress or not request.
    codeActionKinds.has_value() or request.codeActionKinds->size() not_eq 1uz or (*request.
    codeActionKinds)[0uz] not_eq Eura::QuickFix or not request.documentation.has_value() or request
    .documentation->size() not_eq 1uz)
        return false;
    const Eura::CodeActionKindDocumentation& documentation = (*request.documentation)[0uz];
    if(documentation.kind not_eq Eura::QuickFix or documentation.command.title not_eq "meow" or not
    documentation.command.tooltip.has_value() or *documentation.command.tooltip not_eq "nya" or
    documentation.command.command not_eq "operation:cute" or not documentation.command.arguments.
    has_value() or documentation.command.arguments->size() not_eq 1uz)
        return false;
    Eura::Message message;
    from_json((*documentation.command.arguments)[0uz], message);
    if(message.jsonrpc not_eq "2.0" or not request.resolveProvider.has_value() or not *request.
    resolveProvider)
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