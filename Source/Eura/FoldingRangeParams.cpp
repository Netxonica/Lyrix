// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FoldingRangeParams.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FoldingRangeParams& folding_range_params) noexcept
    -> void
    {
        from_json(object, static_cast<WorkDoneProgressParams&>(folding_range_params));
        from_json(object, static_cast<PartialResultParams&>(folding_range_params));
        folding_range_params.textDocument = object.at("textDocument").get<TextDocumentIdentifier>()
        ;
    }

    auto to_json(nlohmann::json& object, const FoldingRangeParams& folding_range_params) noexcept
    -> void
    {
        to_json(object, static_cast<const WorkDoneProgressParams&>(folding_range_params));
        to_json(object, static_cast<const PartialResultParams&>(folding_range_params));
        object["textDocument"] = folding_range_params.textDocument;
    }
}

#endif