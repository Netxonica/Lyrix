// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/NotebookDocumentFilter.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    const std::string content = "{\"notebookType\":\"lyrix\",\"scheme\":\"meow.lyrix\",\"pattern\":{\"baseUri\":{\"uri\":\"meow.extension\",\"name\":\"meow nya\"},\"pattern\":\"*.extension\"}}";
    const nlohmann::json root = nlohmann::json::parse(content);
    Eura::NotebookDocumentFilter request;
    Eura::from_json(root, request);
    if(not request.notebookType.has_value() or *request.notebookType not_eq "lyrix" or not request.
    scheme.has_value() or *request.scheme not_eq "meow.lyrix" or not request.pattern.has_value() or
    not std::holds_alternative<Eura::RelativePattern>(*request.pattern))
        return false;
    const Eura::RelativePattern& relative_pattern = std::get<Eura::RelativePattern>(*request.
    pattern);
    if(not std::holds_alternative<Eura::WorkspaceFolder>(relative_pattern.baseUri))
        return false;
    const Eura::WorkspaceFolder& workspace_folder = std::get<Eura::WorkspaceFolder>(
    relative_pattern.baseUri);
    if(workspace_folder.uri not_eq "meow.extension" or workspace_folder.name not_eq "meow nya" or
    relative_pattern.pattern not_eq "*.extension")
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