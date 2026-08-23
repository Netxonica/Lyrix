// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_folding_range_kind
#define lyrix_header_guard_eura_folding_range_kind
#include <string>

namespace Eura
{
    using FoldingRangeKind = std::string;

    inline const FoldingRangeKind Comment = "comment", Imports = "imports", Region = "region";
}

#endif
#endif