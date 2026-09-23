// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/CompletionItem.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"label\":\"meow\",\"labelDetails\":{\"detail\":\"meow\",\"description\":\"nya\"},\"kind\":14,\"tags\":[1],\"detail\":\"nya\",\"documentation\":\"uwu\",\"preselect\":true,\"sortText\":\"meow\",\"filterText\":\"nya\",\"insertText\":\"uwu\",\"insertTextFormat\":2,\"insertTextMode\":2,\"textEdit\":{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"},\"textEditText\":\"skibidi\",\"additionalTextEdits\":[{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"}],\"commitCharacters\":[\"fanum\"],\"command\":{\"title\":\"meow\",\"tooltip\":\"nya\",\"command\":\"operation:cute\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]},\"data\":{\"jsonrpc\":\"2.0\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionItem request;
    Eura::from_json(root, request);
    if(request.label not_eq "meow" or not request.labelDetails.has_value() or not request.
    labelDetails->detail.has_value() or *request.labelDetails->detail not_eq "meow" or not request.
    labelDetails->description.has_value() or *request.labelDetails->description not_eq "nya" or not
    request.kind.has_value() or *request.kind not_eq Eura::CompletionItemKind::Keyword or not
    request.tags.has_value() or request.tags->size() not_eq 1uz or (*request.tags)[0uz] not_eq Eura
    ::CompletionItemTag::Deprecated or not request.detail.has_value() or *request.detail not_eq
    "nya" or not request.documentation.has_value() or not std::holds_alternative<std::string>(*
    request.documentation) or std::get<std::string>(*request.documentation) not_eq "uwu" or not
    request.preselect.has_value() or not *request.preselect or not request.sortText.has_value() or 
    *request.sortText not_eq "meow" or not request.filterText.has_value() or *request.filterText
    not_eq "nya" or not request.insertText.has_value() or *request.insertText not_eq "uwu" or not
    request.insertTextFormat.has_value() or *request.insertTextFormat not_eq Eura::InsertTextFormat
    ::Snippet or not request.insertTextMode.has_value() or *request.insertTextMode not_eq Eura::
    InsertTextMode::AdjustIndentation or not request.textEdit.has_value() or not std::
    holds_alternative<Eura::TextEdit>(*request.textEdit))
        return false;
    const Eura::TextEdit& textEdit = std::get<Eura::TextEdit>(*request.textEdit);
    if(textEdit.range.start.line not_eq 0u or textEdit.range.start.character not_eq 0u or textEdit.
    range.end.line not_eq 42u or textEdit.range.end.character not_eq 67u or textEdit.newText not_eq
    "meow nya" or not request.textEditText.has_value() or *request.textEditText not_eq "skibidi" or
    not request.additionalTextEdits.has_value() or request.additionalTextEdits->size() not_eq 1uz
    or (*request.additionalTextEdits)[0uz].range.start.line not_eq 0u or (*request.
    additionalTextEdits)[0uz].range.start.character not_eq 0u or (*request.additionalTextEdits)[0uz
    ].range.end.line not_eq 42u or (*request.additionalTextEdits)[0uz].range.end.character not_eq
    67u or (*request.additionalTextEdits)[0uz].newText not_eq "meow nya" or not request.
    commitCharacters.has_value() or request.commitCharacters->size() not_eq 1uz or (*request.
    commitCharacters)[0uz] not_eq "fanum" or not request.command.has_value() or request.command->
    title not_eq "meow" or not request.command->tooltip.has_value() or *request.command->tooltip
    not_eq "nya" or request.command->command not_eq "operation:cute" or not request.command->
    arguments.has_value() or request.command->arguments->size() not_eq 1uz)
        return false;
    Eura::Message message;
    from_json((*request.command->arguments)[0uz], message);
    if(message.jsonrpc not_eq "2.0" or not request.data.has_value())
        return false;
    Eura::Message message2;
    from_json(*request.data, message2);
    if(message2.jsonrpc not_eq "2.0")
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