// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_file_operation_pattern_kind
#define lyrix_header_guard_eura_file_operation_pattern_kind
#include <string>

namespace Eura
{
    using FileOperationPatternKind = std::string;

    inline const FileOperationPatternKind File = "file", Folder = "folder";
}

#endif
#endif