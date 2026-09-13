// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/InlineValueRegistrationOptions.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"workDoneProgress\":true,\"documentSelector\":[{\"language\":\"lyrix\",\"scheme\":\"meow.lyrix\",\"pattern\":{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}},{\"notebook\":{\"notebookType\":\"lyrix\",\"scheme\":\"meow.lyrix\",\"pattern\":{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}},\"language\":\"lyrix\"}],\"id\":\"meow\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::InlineValueRegistrationOptions request;
    Eura::from_json(root, request);
    if(not request.workDoneProgress.has_value() or not *request.workDoneProgress or not std::
    holds_alternative<Eura::DocumentSelector>(request.documentSelector))
        return false;
    const Eura::DocumentSelector& documentSelector = std::get<Eura::DocumentSelector>(request.
    documentSelector);
    if(documentSelector.size() not_eq 2uz or not std::holds_alternative<Eura::TextDocumentFilter>(
    documentSelector[0uz]) or not std::holds_alternative<Eura::NotebookCellTextDocumentFilter>(
    documentSelector[1uz]))
        return false;
    const Eura::TextDocumentFilter& text_document_filter = std::get<Eura::TextDocumentFilter>(
    documentSelector[0uz]);
    if(not text_document_filter.language.has_value() or *text_document_filter.language not_eq
    "lyrix" or not text_document_filter.scheme.has_value() or *text_document_filter.scheme not_eq
    "meow.lyrix" or not text_document_filter.pattern.has_value() or not std::holds_alternative<Eura
    ::RelativePattern>(*text_document_filter.pattern))
        return false;
    const Eura::RelativePattern& relative_pattern = std::get<Eura::RelativePattern>(*
    text_document_filter.pattern);
    if(not std::holds_alternative<Eura::WorkspaceFolder>(relative_pattern.baseUri))
        return false;
    const Eura::WorkspaceFolder& workspace_folder = std::get<Eura::WorkspaceFolder>(
    relative_pattern.baseUri);
    if(workspace_folder.uri not_eq "meow.extension" or workspace_folder.name not_eq "meow nya" or
    relative_pattern.pattern not_eq "*.extension")
        return false;
    const Eura::NotebookCellTextDocumentFilter& notebook_cell_text_document_filter = std::get<Eura
    ::NotebookCellTextDocumentFilter>(documentSelector[1uz]);
    if(not std::holds_alternative<Eura::NotebookDocumentFilter>(notebook_cell_text_document_filter.
    notebook))
        return false;
    const Eura::NotebookDocumentFilter& notebook = std::get<Eura::NotebookDocumentFilter>(
    notebook_cell_text_document_filter.notebook);
    if(not notebook.notebookType.has_value() or *notebook.notebookType not_eq "lyrix" or not
    notebook.scheme.has_value() or *notebook.scheme not_eq "meow.lyrix" or not notebook.pattern.
    has_value() or not std::holds_alternative<Eura::RelativePattern>(*notebook.pattern))
        return false;
    const Eura::RelativePattern& rrelative_pattern = std::get<Eura::RelativePattern>(*notebook.
    pattern);
    if(not std::holds_alternative<Eura::WorkspaceFolder>(rrelative_pattern.baseUri))
        return false;
    const Eura::WorkspaceFolder& wworkspace_folder = std::get<Eura::WorkspaceFolder>(
    rrelative_pattern.baseUri);
    if(wworkspace_folder.uri not_eq "meow.extension" or wworkspace_folder.name not_eq "meow nya" or
    rrelative_pattern.pattern not_eq "*.extension" or not notebook_cell_text_document_filter.
    language.has_value() or *notebook_cell_text_document_filter.language not_eq "lyrix" or not
    request.id.has_value() or *request.id not_eq "meow")
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