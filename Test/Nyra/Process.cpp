// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Process.hpp"
#include "Nyra/Directory.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    {
        const std::optional<Nyra::Process> process = Nyra::create_process("process_test", std::
        vector<std::string>{
        #ifdef lyrix_windows
        "-Command", "New-Item", "-ItemType", "Directory", "-Name", "\"nya\""
        #else
        "nya"
        #endif
        });
        if(not process.has_value())
            return false;
    }
    return Nyra::Directory::Exists("nya");
}

int main()
{
    return not lyrix_test();
}

#endif