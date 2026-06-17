// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_markup_kind
#define lyrix_header_guard_eura_markup_kind
#include "Eura/String.hpp"

namespace Eura
{
    using MarkupKind = Json::String;

    inline const constexpr MarkupKind PlainText = "plaintext", Markdown = "markdown";
}

#endif
#endif