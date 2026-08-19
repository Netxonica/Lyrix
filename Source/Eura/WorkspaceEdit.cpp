// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceEdit.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, WorkspaceEdit& workspace_edit) noexcept -> void
    {
        if(object.contains("changes"))
            workspace_edit.changes = object.at("changes").get<std::unordered_map<DocumentUri, std::
            vector<TextEdit>>>();
        if(object.contains("documentChanges"))
        {
            workspace_edit.documentChanges = std::vector<std::variant<TextDocumentEdit, CreateFile,
            RenameFile, DeleteFile>>{};
            const nlohmann::json& documentChanges = object.at("documentChanges");
            for(const nlohmann::json& documentChange : documentChanges)
            {
                if(not documentChange.contains("kind"))
                    workspace_edit.documentChanges->emplace_back(documentChange.get<
                    TextDocumentEdit>());
                else
                {
                    const std::string kind = documentChange.at("kind").get<std::string>();
                    if(kind == "create")
                        workspace_edit.documentChanges->emplace_back(documentChange.get<CreateFile>
                        ());
                    else if(kind == "rename")
                        workspace_edit.documentChanges->emplace_back(documentChange.get<RenameFile>
                        ());
                    else
                        workspace_edit.documentChanges->emplace_back(documentChange.get<DeleteFile>
                        ());
                }
            }
        }
        if(object.contains("changeAnnotations"))
            workspace_edit.changeAnnotations = object.at("changeAnnotations").get<std::
            unordered_map<ChangeAnnotationIdentifier, ChangeAnnotation>>();
    }

    auto to_json(nlohmann::json& object, const WorkspaceEdit& workspace_edit) noexcept -> void
    {
        if(workspace_edit.changes.has_value())
            object["changes"] = *workspace_edit.changes;
        if(workspace_edit.documentChanges.has_value())
        {
            nlohmann::json documentChanges = nlohmann::json::array();
            for(const std::variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>&
            documentChange : *workspace_edit.documentChanges)
                std::visit([&documentChanges](auto&& documentChange)
                {
                    documentChanges.emplace_back(documentChange);
                }, documentChange);
            object["documentChanges"] = documentChanges;
        }
        if(workspace_edit.changeAnnotations.has_value())
            object["changeAnnotations"] = *workspace_edit.changeAnnotations;
    }
}

#endif