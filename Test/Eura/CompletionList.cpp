// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Message.hpp"
#include "Eura/CompletionList.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"isIncomplete\":true,\"itemDefaults\":{\"commitCharacters\":[\"meow\"],\"editRange\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"insertTextFormat\":2,\"insertTextMode\":2,\"data\":{\"jsonrpc\":\"2.0\"}},\"applyKind\":{\"commitCharacters\":1,\"data\":2},\"items\":[{\"label\":\"meow\",\"labelDetails\":{\"detail\":\"meow\",\"description\":\"nya\"},\"kind\":14,\"tags\":[1],\"detail\":\"nya\",\"documentation\":\"uwu\",\"preselect\":true,\"sortText\":\"meow\",\"filterText\":\"nya\",\"insertText\":\"uwu\",\"insertTextFormat\":2,\"insertTextMode\":2,\"textEdit\":{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"},\"textEditText\":\"skibidi\",\"additionalTextEdits\":[{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"}],\"commitCharacters\":[\"fanum\"],\"command\":{\"title\":\"meow\",\"tooltip\":\"nya\",\"command\":\"operation:cute\",\"arguments\":[{\"jsonrpc\":\"2.0\"}]},\"data\":{\"jsonrpc\":\"2.0\"}}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::CompletionList request;
    Eura::from_json(root, request);
    if(not request.isIncomplete or not request.itemDefaults.has_value() or not request.itemDefaults
    ->commitCharacters.has_value() or request.itemDefaults->commitCharacters->size() not_eq 1uz or
    (*request.itemDefaults->commitCharacters)[0uz] not_eq "meow" or not request.itemDefaults->
    editRange.has_value() or not std::holds_alternative<Eura::Range>(*request.itemDefaults->
    editRange))
        return false;
    const Eura::Range& range = std::get<Eura::Range>(*request.itemDefaults->editRange);
    if(range.start.line not_eq 0u or range.start.character not_eq 0u or range.end.line not_eq 42u
    or range.end.character not_eq 67u or not request.itemDefaults->insertTextFormat.has_value() or
    *request.itemDefaults->insertTextFormat not_eq Eura::InsertTextFormat::Snippet or not request.
    itemDefaults->insertTextMode.has_value() or *request.itemDefaults->insertTextMode not_eq Eura::
    InsertTextMode::AdjustIndentation or not request.itemDefaults->data.has_value())
        return false;
    Eura::Message message;
    Eura::from_json(*request.itemDefaults->data, message);
    if(message.jsonrpc not_eq "2.0" or not request.applyKind.has_value() or not request.applyKind->
    commitCharacters.has_value() or *request.applyKind->commitCharacters not_eq Eura::ApplyKind::
    Replace or not request.applyKind->data.has_value() or *request.applyKind->data not_eq Eura::
    ApplyKind::Merge or request.items.size() not_eq 1uz or request.items[0uz].label not_eq "meow"
    or not request.items[0uz].labelDetails.has_value() or not request.items[0uz].labelDetails->
    detail.has_value() or *request.items[0uz].labelDetails->detail not_eq "meow" or not request.
    items[0uz].labelDetails->description.has_value() or *request.items[0uz].labelDetails->
    description not_eq "nya" or not request.items[0uz].kind.has_value() or *request.items[0uz].kind
    not_eq Eura::CompletionItemKind::Keyword or not request.items[0uz].tags.has_value() or request.
    items[0uz].tags->size() not_eq 1uz or (*request.items[0uz].tags)[0uz] not_eq Eura::
    CompletionItemTag::Deprecated or not request.items[0uz].detail.has_value() or *request.items[
    0uz].detail not_eq "nya" or not request.items[0uz].documentation.has_value() or not std::
    holds_alternative<std::string>(*request.items[0uz].documentation) or std::get<std::string>(*
    request.items[0uz].documentation) not_eq "uwu" or not request.items[0uz].preselect.has_value()
    or not *request.items[0uz].preselect or not request.items[0uz].sortText.has_value() or *request
    .items[0uz].sortText not_eq "meow" or not request.items[0uz].filterText.has_value() or *request
    .items[0uz].filterText not_eq "nya" or not request.items[0uz].insertText.has_value() or *
    request.items[0uz].insertText not_eq "uwu" or not request.items[0uz].insertTextFormat.has_value
    () or *request.items[0uz].insertTextFormat not_eq Eura::InsertTextFormat::Snippet or not
    request.items[0uz].insertTextMode.has_value() or *request.items[0uz].insertTextMode not_eq Eura
    ::InsertTextMode::AdjustIndentation or not request.items[0uz].textEdit.has_value() or not std::
    holds_alternative<Eura::TextEdit>(*request.items[0uz].textEdit))
        return false;
    const Eura::TextEdit& textEdit = std::get<Eura::TextEdit>(*request.items[0uz].textEdit);
    if(textEdit.range.start.line not_eq 0u or textEdit.range.start.character not_eq 0u or textEdit.
    range.end.line not_eq 42u or textEdit.range.end.character not_eq 67u or textEdit.newText not_eq
    "meow nya" or not request.items[0uz].textEditText.has_value() or *request.items[0uz].
    textEditText not_eq "skibidi" or not request.items[0uz].additionalTextEdits.has_value() or
    request.items[0uz].additionalTextEdits->size() not_eq 1uz or (*request.items[0uz].
    additionalTextEdits)[0uz].range.start.line not_eq 0u or (*request.items[0uz].
    additionalTextEdits)[0uz].range.start.character not_eq 0u or (*request.items[0uz].
    additionalTextEdits)[0uz].range.end.line not_eq 42u or (*request.items[0uz].additionalTextEdits
    )[0uz].range.end.character not_eq 67u or (*request.items[0uz].additionalTextEdits)[0uz].newText
    not_eq "meow nya" or not request.items[0uz].commitCharacters.has_value() or request.items[0uz].
    commitCharacters->size() not_eq 1uz or (*request.items[0uz].commitCharacters)[0uz] not_eq
    "fanum" or not request.items[0uz].command.has_value() or request.items[0uz].command->title
    not_eq "meow" or not request.items[0uz].command->tooltip.has_value() or *request.items[0uz].
    command->tooltip not_eq "nya" or request.items[0uz].command->command not_eq "operation:cute" or
    not request.items[0uz].command->arguments.has_value() or request.items[0uz].command->arguments
    ->size() not_eq 1uz)
        return false;
    Eura::Message message2;
    from_json((*request.items[0uz].command->arguments)[0uz], message2);
    if(message2.jsonrpc not_eq "2.0" or not request.items[0uz].data.has_value())
        return false;
    Eura::Message message3;
    from_json(*request.items[0uz].data, message3);
    if(message3.jsonrpc not_eq "2.0")
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