// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_progress_token
#define lyrix_header_guard_eura_progress_token
#include <variant>
#include "Eura/String.hpp"
#include "Eura/Integer.hpp"

namespace Eura
{
    using ProgressToken = std::variant<Json::Integer, Json::String>;
}

#endif
#endif