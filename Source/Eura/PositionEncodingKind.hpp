// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_position_encoding_kind
#define lyrix_header_guard_eura_position_encoding_kind
#include <string>

namespace Eura
{
    using PositionEncodingKind = std::string;

    inline const PositionEncodingKind UTF8 = "utf-8", UTF16 = "utf-16", UTF32 = "utf-32";
}

#endif
#endif