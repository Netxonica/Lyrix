// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentEdit.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"textDocument\":{\"uri\":\"meow.extension\",\"version\":null},\"edits\":[{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"},{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\",\"annotationId\":\"meow\"},{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"snippet\":{\"kind\":\"snippet\",\"value\":\"meow nya\"},\"annotationId\":\"meow\"}]}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::TextDocumentEdit request;
    Eura::from_json(root, request);
    if(request.textDocument.uri not_eq "meow.extension" or not std::holds_alternative<std::
    nullptr_t>(request.textDocument.version) or request.edits.size() not_eq 3uz or not std::
    holds_alternative<Eura::TextEdit>(request.edits[0u]) or not std::holds_alternative<Eura::
    AnnotatedTextEdit>(request.edits[1u]) or not std::holds_alternative<Eura::SnippetTextEdit>(
    request.edits[2u]))
        return false;
    const Eura::TextEdit& text_edit = std::get<Eura::TextEdit>(request.edits[0uz]);
    if(text_edit.range.start.line not_eq 0u or text_edit.range.start.character not_eq 0u or
    text_edit.range.end.line not_eq 42u or text_edit.range.end.character not_eq 67u or text_edit.
    newText not_eq "meow nya")
        return false;
    const Eura::AnnotatedTextEdit& annotated_text_edit = std::get<Eura::AnnotatedTextEdit>(request.
    edits[1uz]);
    if(annotated_text_edit.range.start.line not_eq 0u or annotated_text_edit.range.start.character
    not_eq 0u or annotated_text_edit.range.end.line not_eq 42u or annotated_text_edit.range.end.
    character not_eq 67u or annotated_text_edit.newText not_eq "meow nya" or annotated_text_edit.
    annotationId not_eq "meow")
        return false;
    const Eura::SnippetTextEdit& snippet_text_edit = std::get<Eura::SnippetTextEdit>(request.edits[
    2uz]);
    if(snippet_text_edit.range.start.line not_eq 0u or snippet_text_edit.range.start.character
    not_eq 0u or snippet_text_edit.range.end.line not_eq 42u or snippet_text_edit.range.end.
    character not_eq 67u or snippet_text_edit.snippet.kind not_eq "snippet" or snippet_text_edit.
    snippet.value not_eq "meow nya" or not snippet_text_edit.annotationId.has_value() or *
    snippet_text_edit.annotationId not_eq "meow")
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