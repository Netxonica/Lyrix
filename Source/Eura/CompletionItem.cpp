// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/CompletionItem.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, CompletionItem& completion_item) noexcept -> void
    {
        completion_item.label = object.at("label").get<std::string>();
        if(object.contains("labelDetails"))
            completion_item.labelDetails = object.at("labelDetails").get<CompletionItemLabelDetails
            >();
        if(object.contains("kind"))
            completion_item.kind = object.at("kind").get<CompletionItemKind>();
        if(object.contains("tags"))
        {
            completion_item.tags = std::vector<CompletionItemTag>{};
            const nlohmann::json& tags = object.at("tags");
            for(const nlohmann::json& tag : tags)
                completion_item.tags->emplace_back(tag.get<CompletionItemTag>());
        }
        if(object.contains("detail"))
            completion_item.detail = object.at("detail").get<std::string>();
        if(object.contains("documentation"))
        {
            const nlohmann::json& documentation = object.at("documentation");
            if(documentation.is_string())
                completion_item.documentation = documentation.get<std::string>();
            else
                completion_item.documentation = documentation.get<MarkupContent>();
        }
        if(object.contains("preselect"))
            completion_item.preselect = object.at("preselect").get<bool>();
        if(object.contains("sortText"))
            completion_item.sortText = object.at("sortText").get<std::string>();
        if(object.contains("filterText"))
            completion_item.filterText = object.at("filterText").get<std::string>();
        if(object.contains("insertText"))
            completion_item.insertText = object.at("insertText").get<std::string>();
        if(object.contains("insertTextFormat"))
            completion_item.insertTextFormat = object.at("insertTextFormat").get<InsertTextFormat>(
            );
        if(object.contains("insertTextMode"))
            completion_item.insertTextMode = object.at("insertTextMode").get<InsertTextMode>();
        if(object.contains("textEdit"))
        {
            const nlohmann::json& textEdit = object.at("textEdit");
            if(textEdit.contains("range"))
                completion_item.textEdit = textEdit.get<TextEdit>();
            else
                completion_item.textEdit = textEdit.get<InsertReplaceEdit>();
        }
        if(object.contains("textEditText"))
            completion_item.textEditText = object.at("textEditText").get<std::string>();
        if(object.contains("additionalTextEdits"))
        {
            completion_item.additionalTextEdits = std::vector<TextEdit>{};
            const nlohmann::json& additionalTextEdits = object.at("additionalTextEdits");
            for(const nlohmann::json& additionalTextEdit : additionalTextEdits)
                completion_item.additionalTextEdits->emplace_back(additionalTextEdit.get<TextEdit>(
                ));
        }
        if(object.contains("commitCharacters"))
        {
            completion_item.commitCharacters = std::vector<std::string>{};
            const nlohmann::json& commitCharacters = object.at("commitCharacters");
            for(const nlohmann::json& commitCharacter : commitCharacters)
                completion_item.commitCharacters->emplace_back(commitCharacter.get<std::string>());
        }
        if(object.contains("command"))
            completion_item.command = object.at("command").get<Command>();
        if(object.contains("data"))
            completion_item.data = object.at("data");
    }

    auto to_json(nlohmann::json& object, const CompletionItem& completion_item) noexcept -> void
    {
        object["label"] = completion_item.label;
        if(completion_item.labelDetails.has_value())
            object["labelDetails"] = *completion_item.labelDetails;
        if(completion_item.kind.has_value())
            object["kind"] = *completion_item.kind;
        if(completion_item.tags.has_value())
        {
            nlohmann::json tags = nlohmann::json::array();
            for(const CompletionItemTag tag : *completion_item.tags)
                tags.emplace_back(tag);
            object["tags"] = tags;
        }
        if(completion_item.detail.has_value())
            object["detail"] = *completion_item.detail;
        if(completion_item.documentation.has_value())
            std::visit([&object](auto&& documentation)
            {
                object["documentation"] = documentation;
            }, *completion_item.documentation);
        if(completion_item.preselect.has_value())
            object["preselect"] = *completion_item.preselect;
        if(completion_item.sortText.has_value())
            object["sortText"] = *completion_item.sortText;
        if(completion_item.filterText.has_value())
            object["filterText"] = *completion_item.filterText;
        if(completion_item.insertText.has_value())
            object["insertText"] = *completion_item.insertText;
        if(completion_item.insertTextFormat.has_value())
            object["insertTextFormat"] = *completion_item.insertTextFormat;
        if(completion_item.insertTextMode.has_value())
            object["insertTextMode"] = *completion_item.insertTextMode;
        if(completion_item.textEdit.has_value())
            std::visit([&object](auto&& textEdit)
            {
                object["textEdit"] = textEdit;
            }, *completion_item.textEdit);
        if(completion_item.textEditText.has_value())
            object["textEditText"] = *completion_item.textEditText;
        if(completion_item.additionalTextEdits.has_value())
        {
            nlohmann::json additionalTextEdits = nlohmann::json::array();
            for(const TextEdit& additionalTextEdit : *completion_item.additionalTextEdits)
                additionalTextEdits.emplace_back(additionalTextEdit);
            object["additionalTextEdits"] = additionalTextEdits;
        }
        if(completion_item.commitCharacters.has_value())
        {
            nlohmann::json commitCharacters = nlohmann::json::array();
            for(const std::string& commitCharacter : *completion_item.commitCharacters)
                commitCharacters.emplace_back(commitCharacter);
            object["commitCharacters"] = commitCharacters;
        }
        if(completion_item.command.has_value())
            object["command"] = *completion_item.command;
        if(completion_item.data.has_value())
            object["data"] = *completion_item.data;
    }
}

#endif