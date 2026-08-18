// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookCellTextDocumentFilter.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"notebook\":{\"notebookType\":\"lyrix\",\"scheme\":\"meow.lyrix\",\"pattern\":{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}},\"language\":\"lyrix\"}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::NotebookCellTextDocumentFilter request;
    Eura::from_json(root, request);
    if(not std::holds_alternative<Eura::NotebookDocumentFilter>(request.notebook))
        return false;
    const Eura::NotebookDocumentFilter& notebook = std::get<Eura::NotebookDocumentFilter>(request.
    notebook);
    if(not notebook.notebookType.has_value() or *notebook.notebookType not_eq "lyrix" or not
    notebook.scheme.has_value() or *notebook.scheme not_eq "meow.lyrix" or not notebook.pattern.
    has_value() or not std::holds_alternative<Eura::RelativePattern>(*notebook.pattern))
        return false;
    const Eura::RelativePattern& relative_pattern = std::get<Eura::RelativePattern>(*notebook.
    pattern);
    if(not std::holds_alternative<Eura::WorkspaceFolder>(relative_pattern.baseUri))
        return false;
    const Eura::WorkspaceFolder& workspace_folder = std::get<Eura::WorkspaceFolder>(
    relative_pattern.baseUri);
    if(workspace_folder.uri not_eq "meow.extension" or workspace_folder.name not_eq "meow nya" or
    relative_pattern.pattern not_eq "*.extension" or not request.language.has_value() or *request.
    language not_eq "lyrix")
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