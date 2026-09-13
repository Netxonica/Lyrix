// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/SelectionRangeRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, SelectionRangeRegistrationOptions&
    selection_range_registration_options) noexcept -> void
    {
        from_json(object, static_cast<SelectionRangeOptions&>(selection_range_registration_options)
        );
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        selection_range_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(
        selection_range_registration_options));
    }

    auto to_json(nlohmann::json& object, const SelectionRangeRegistrationOptions&
    selection_range_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const SelectionRangeOptions&>(
        selection_range_registration_options));
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        selection_range_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        selection_range_registration_options));
    }
}

#endif