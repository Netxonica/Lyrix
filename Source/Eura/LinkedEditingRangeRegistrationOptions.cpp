// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/LinkedEditingRangeRegistrationOptions.hpp"

namespace Eura
{
    auto from_json(const nlohmann::json& object, LinkedEditingRangeRegistrationOptions&
    linked_editing_range_registration_options) noexcept -> void
    {
        from_json(object, static_cast<TextDocumentRegistrationOptions&>(
        linked_editing_range_registration_options));
        from_json(object, static_cast<LinkedEditingRangeOptions&>(
        linked_editing_range_registration_options));
        from_json(object, static_cast<StaticRegistrationOptions&>(
        linked_editing_range_registration_options));
    }

    auto to_json(nlohmann::json& object, const LinkedEditingRangeRegistrationOptions&
    linked_editing_range_registration_options) noexcept -> void
    {
        to_json(object, static_cast<const TextDocumentRegistrationOptions&>(
        linked_editing_range_registration_options));
        to_json(object, static_cast<const LinkedEditingRangeOptions&>(
        linked_editing_range_registration_options));
        to_json(object, static_cast<const StaticRegistrationOptions&>(
        linked_editing_range_registration_options));
    }
}

#endif