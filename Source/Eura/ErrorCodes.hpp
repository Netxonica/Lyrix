// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_eura_error_codes
#define lyrix_header_guard_eura_error_codes
#include <cstdint>

namespace Eura
{
    enum class [[nodiscard]] ErrorCodes : std::int32_t
    {
        ParseError = -32700,
        InvalidRequest = -32600,
        MethodNotFound = -32601,
        InvalidParams = -32602,
        InternalError = -32603,
        JsonrpcReservedErrorRangeStart = -32099,
        ServerNotInitialized = -32002,
	    UnknownErrorCode = -32001,
        JsonrpcReservedErrorRangeEnd = -32000,
        LspReservedErrorRangeStart = -32899,
	    RequestFailed = -32803,
	    ServerCancelled = -32802,
	    ContentModified = -32801,
	    RequestCancelled = -32800,
	    LspReservedErrorRangeEnd = -32800
    };
}

#endif
#endif