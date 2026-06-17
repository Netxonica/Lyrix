// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/WorkspaceEdit.hpp"

namespace Eura
{
    auto Deserialize(const Json::Object& object, WorkspaceEdit& workspace_edit) noexcept -> void
    {
        if(object.Contains("changes"))
        {
            workspace_edit.changes = std::unordered_map<DocumentUri, std::vector<TextEdit>>{};
            const Json::Object& changes = object.Retrieve("changes").As<Json::Object>();
            for(const std::pair<Json::String, Json::Any>& change : changes.fields)
            {
                std::vector<TextEdit> edits;
                const Json::Array& text_edits = change.second.As<Json::Array>();
                for(const Json::Any& text_edit : text_edits)
                {
                    TextEdit edit;
                    Deserialize(text_edit.As<Json::Object>(), edit);
                    edits.emplace_back(edit);
                }
                workspace_edit.changes->emplace(change.first, edits);
            }
        }
        if(object.Contains("documentChanges"))
        {
            workspace_edit.documentChanges = std::vector<std::variant<TextDocumentEdit, CreateFile,
            RenameFile, DeleteFile>>{};
            const Json::Array& documentChanges = object.Retrieve("documentChanges").As<Json::Array>
            ();
            for(const Json::Any& documentChange : documentChanges)
            {
                const Json::Object& change = documentChange.As<Json::Object>();
                if(change.Contains("textDocument"))
                {
                    TextDocumentEdit edit;
                    Deserialize(change, edit);
                    workspace_edit.documentChanges->emplace_back(edit);
                }
                else
                {
                    const Json::String kind = change.Retrieve("kind").As<Json::String>();
                    if(kind == "create")
                    {
                        CreateFile file;
                        Deserialize(change, file);
                        workspace_edit.documentChanges->emplace_back(file);
                    }
                    else if(kind == "rename")
                    {
                        RenameFile file;
                        Deserialize(change, file);
                        workspace_edit.documentChanges->emplace_back(file);
                    }
                    else if(kind == "delete")
                    {
                        DeleteFile file;
                        Deserialize(change, file);
                        workspace_edit.documentChanges->emplace_back(file);
                    }
                    else
                        std::abort();
                }
            }
        }
        if(object.Contains("changeAnnotations"))
        {
            workspace_edit.changeAnnotations = std::unordered_map<ChangeAnnotationIdentifier,
            ChangeAnnotation>{};
            const Json::Object& changeAnnotations = object.Retrieve("changeAnnotations").As<Json::
            Object>();
            for(const std::pair<Json::String, Json::Any>& changeAnnotation : changeAnnotations.
            fields)
            {
                ChangeAnnotation annotation;
                Deserialize(changeAnnotation.second.As<Json::Object>(), annotation);
                workspace_edit.changeAnnotations->emplace(changeAnnotation.first, annotation);
            }
        }
    }

    auto Serialize(Json::Object& object, const WorkspaceEdit& workspace_edit) noexcept -> void
    {
        if(workspace_edit.changes.has_value())
        {
            Json::Object& changes = object.NestedObject("changes");
            for(const auto& [key, value] : *workspace_edit.changes)
            {
                Json::Array& change = changes.NestedArray(key);
                for(const TextEdit& edit : value)
                {
                    change.emplace_back(Json::Object{});
                    Serialize(change.back().As<Json::Object>(), edit);
                }
            }
        }
        if(workspace_edit.documentChanges.has_value())
        {
            Json::Array& documentChanges = object.NestedArray("documentChanges");
            for(const std::variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>&
            documentChange : *workspace_edit.documentChanges)
                documentChange.visit([&documentChanges](auto&& change)
                {
                    documentChanges.emplace_back(Json::Object{});
                    Serialize(documentChanges.back().As<Json::Object>(), change);
                });
        }
        if(workspace_edit.changeAnnotations.has_value())
        {
            Json::Object& changeAnnotations = object.NestedObject("changeAnnotations");
            for(const auto& [id, value] : *workspace_edit.changeAnnotations)
            {
                changeAnnotations.fields.emplace_back(id, Json::Object{});
                Serialize(changeAnnotations.fields.back().second.As<Json::Object>(), value);
            }
        }
    }
}

#endif