// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/FoldingRangeRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, FoldingRangeRegistrationOptions&
    folding_range_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        folding_range_registration_options));
        from_json(object, static_cast<FoldingRangeOptions&>(folding_range_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(
        folding_range_registration_options));
    }

    auto to_json(nlohmann::json& object, const FoldingRangeRegistrationOptions&
    folding_range_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        folding_range_registration_options));
        to_json(object, static_cast<const FoldingRangeOptions&>(folding_range_registration_options)
        );
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        folding_range_registration_options));
    }
}

#endif