// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/TextDocumentRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, TextDocumentRegistrationOptions&
    text_document_registration_options) noexcept -> void
    {
        const nlohmann::json& documentSelector = object.at("documentSelector");
        if(documentSelector.is_null())
            text_document_registration_options.documentSelector = nullptr;
        else
        {
            text_document_registration_options.documentSelector = DocumentSelector{};
            for(const nlohmann::json& document : documentSelector)
            {
                if(document.contains("notebook"))
                    std::get<DocumentSelector>(text_document_registration_options.documentSelector)
                    .emplace_back(document.get<NotebookCellTextDocumentFilter>());
                else
                    std::get<DocumentSelector>(text_document_registration_options.documentSelector)
                    .emplace_back(document.get<TextDocumentFilter>());
            }
        }
    }

    auto to_json(nlohmann::json& object, const TextDocumentRegistrationOptions&
    text_document_registration_options) noexcept -> void
    {
        if(std::holds_alternative<std::nullptr_t>(text_document_registration_options.
        documentSelector))
            object["documentSelector"] = nullptr;
        else
        {
            nlohmann::json documentSelector = nlohmann::json::array();
            [[maybe_unused]] const DocumentSelector& document = std::get<DocumentSelector>(
            text_document_registration_options.documentSelector);
            for(const DocumentFilter& filter : document)
                std::visit([&documentSelector](auto&& filter)
                {
                    documentSelector.emplace_back(filter);
                }, filter);
            object["documentSelector"] = documentSelector;
        }
    }
}

#endif