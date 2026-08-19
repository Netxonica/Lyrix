// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceEdit.hpp"
#include "Eura/CreateFile.hpp"
#include "Eura/RenameFile.hpp"
#include "Eura/DeleteFile.hpp"
#include "Eura/TextDocumentEdit.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"changes\":{\"meow.extension\":[{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"}]},\"documentChanges\":[{\"textDocument\":{\"uri\":\"meow.extension\",\"version\":null},\"edits\":[{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\"},{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"newText\":\"meow nya\",\"annotationId\":\"meow\"},{\"range\":{\"start\":{\"line\":0,\"character\":0},\"end\":{\"line\":42,\"character\":67}},\"snippet\":{\"kind\":\"snippet\",\"value\":\"meow nya\"},\"annotationId\":\"meow\"}]},{\"kind\":\"create\",\"uri\":\"meow.extension\",\"options\":{\"overwrite\":true,\"ignoreIfExists\":true},\"annotationId\":\"meow\"},{\"kind\":\"rename\",\"oldUri\":\"meow.extension\",\"newUri\":\"nya.extension\",\"options\":{\"overwrite\":true,\"ignoreIfExists\":true},\"annotationId\":\"meow\"},{\"kind\":\"delete\",\"uri\":\"meow.extension\",\"options\":{\"recursive\":true,\"ignoreIfNotExists\":true},\"annotationId\":\"meow\"}],\"changeAnnotations\":{\"meow\":{\"label\":\"meow\",\"needsConfirmation\":true,\"description\":\"meow nya\"}}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::WorkspaceEdit request;
    Eura::from_json(root, request);
    if(not request.changes.has_value() or request.changes->size() not_eq 1uz or not request.changes
    ->contains("meow.extension"))
        return false;
    const std::vector<Eura::TextEdit>& text_edits = request.changes->at("meow.extension");
    if(text_edits.size() not_eq 1uz)
        return false;
    const Eura::TextEdit& stext_edit = text_edits[0uz];
    if(stext_edit.range.start.line not_eq 0u or stext_edit.range.start.character not_eq 0u or
    stext_edit.range.end.line not_eq 42u or stext_edit.range.end.character not_eq 67u or stext_edit
    .newText not_eq "meow nya" or not request.documentChanges.has_value() or request.
    documentChanges->size() not_eq 4uz or not std::holds_alternative<Eura::TextDocumentEdit>((*
    request.documentChanges)[0uz]) or not std::holds_alternative<Eura::CreateFile>((*request.
    documentChanges)[1uz]) or not std::holds_alternative<Eura::RenameFile>((*request.
    documentChanges)[2uz]) or not std::holds_alternative<Eura::DeleteFile>((*request.
    documentChanges)[3uz]))
        return false;
    const Eura::TextDocumentEdit& text_document_edit = std::get<Eura::TextDocumentEdit>((*request.
    documentChanges)[0uz]);
    if(text_document_edit.textDocument.uri not_eq "meow.extension" or not std::holds_alternative<
    std::nullptr_t>(text_document_edit.textDocument.version) or text_document_edit.edits.size()
    not_eq 3uz or not std::holds_alternative<Eura::TextEdit>(text_document_edit.edits[0uz]) or not
    std::holds_alternative<Eura::AnnotatedTextEdit>(text_document_edit.edits[1uz]) or not std::
    holds_alternative<Eura::SnippetTextEdit>(text_document_edit.edits[2uz]))
        return false;
    const Eura::TextEdit& text_edit = std::get<Eura::TextEdit>(text_document_edit.edits[0uz]);
    if(text_edit.range.start.line not_eq 0u or text_edit.range.start.character not_eq 0u or
    text_edit.range.end.line not_eq 42u or text_edit.range.end.character not_eq 67u or text_edit.
    newText not_eq "meow nya")
        return false;
    const Eura::AnnotatedTextEdit& annotated_text_edit = std::get<Eura::AnnotatedTextEdit>(
    text_document_edit.edits[1uz]);
    if(annotated_text_edit.range.start.line not_eq 0u or annotated_text_edit.range.start.character
    not_eq 0u or annotated_text_edit.range.end.line not_eq 42u or annotated_text_edit.range.end.
    character not_eq 67u or annotated_text_edit.newText not_eq "meow nya" or annotated_text_edit.
    annotationId not_eq "meow")
        return false;
    const Eura::SnippetTextEdit& snippet_text_edit = std::get<Eura::SnippetTextEdit>(
    text_document_edit.edits[2uz]);
    if(snippet_text_edit.range.start.line not_eq 0u or snippet_text_edit.range.start.character
    not_eq 0u or snippet_text_edit.range.end.line not_eq 42u or snippet_text_edit.range.end.
    character not_eq 67u or snippet_text_edit.snippet.kind not_eq "snippet" or snippet_text_edit.
    snippet.value not_eq "meow nya" or not snippet_text_edit.annotationId.has_value() or *
    snippet_text_edit.annotationId not_eq "meow")
        return false;
    const Eura::CreateFile& create_file = std::get<Eura::CreateFile>((*request.documentChanges)[1uz
    ]);
    if(create_file.kind not_eq "create" or create_file.uri not_eq "meow.extension" or not
    create_file.options.has_value() or not create_file.options->overwrite.has_value() or not *
    create_file.options->overwrite or not create_file.options->ignoreIfExists.has_value() or not *
    create_file.options->ignoreIfExists or not create_file.annotationId.has_value() or *create_file
    .annotationId not_eq "meow")
        return false;
    const Eura::RenameFile& rename_file = std::get<Eura::RenameFile>((*request.documentChanges)[2uz
    ]);
    if(rename_file.kind not_eq "rename" or rename_file.oldUri not_eq "meow.extension" or
    rename_file.newUri not_eq "nya.extension" or not rename_file.options.has_value() or not
    rename_file.options->overwrite.has_value() or not *rename_file.options->overwrite or not
    rename_file.options->ignoreIfExists.has_value() or not *rename_file.options->ignoreIfExists or
    not rename_file.annotationId.has_value() or *rename_file.annotationId not_eq "meow")
        return false;
    const Eura::DeleteFile& delete_file = std::get<Eura::DeleteFile>((*request.documentChanges)[3uz
    ]);
    if(delete_file.kind not_eq "delete" or delete_file.uri not_eq "meow.extension" or not
    delete_file.options.has_value() or not delete_file.options->recursive.has_value() or not *
    delete_file.options->recursive or not delete_file.options->ignoreIfNotExists.has_value() or not
    *delete_file.options->ignoreIfNotExists or not delete_file.annotationId.has_value() or *
    delete_file.annotationId not_eq "meow" or not request.changeAnnotations.has_value() or request.
    changeAnnotations->size() not_eq 1uz or not request.changeAnnotations->contains("meow"))
        return false;
    const Eura::ChangeAnnotation& change_annotation = request.changeAnnotations->at("meow");
    if(change_annotation.label not_eq "meow" or not change_annotation.needsConfirmation.has_value()
    or not *change_annotation.needsConfirmation or not change_annotation.description.has_value() or
    *change_annotation.description not_eq "meow nya")
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