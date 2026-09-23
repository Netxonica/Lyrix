// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_uniqueness_level
#define lyrix_header_guard_eura_uniqueness_level
#include <string>

namespace Eura
{
    using UniquenessLevel = std::string;

    inline const UniquenessLevel Document = "document", Project = "project", Group = "group",
    Scheme = "scheme", Global = "global";
}

#endif
#endif