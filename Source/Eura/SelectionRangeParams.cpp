// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SelectionRangeParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SelectionRangeParams& selection_range_params)
    noexcept -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(selection_range_params));
        from_json(object, static_cast<PartialResultParams&>(selection_range_params));
        selection_range_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>
        ();
        const nlohmann::json& positions = object.at("positions");
        for(const nlohmann::json& position : positions)
            selection_range_params.positions.emplace_back(position.get<Position>());
    }

    auto to_json(nlohmann::json& object, const SelectionRangeParams& selection_range_params)
    noexcept -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(selection_range_params));
        to_json(object, static_cast<const PartialResultParams&>(selection_range_params));
        object["textDocument"] = selection_range_params.textDocument;
        nlohmann::json positions = nlohmann::json::array();
        for(const Position& position : selection_range_params.positions)
            positions.emplace_back(position);
        object["positions"] = positions;
    }
}

#endif