// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Nyra/Process.hpp"
#include "Nyra/Directory.hpp"

[[nodiscard]] auto lyrix_test() noexcept -> bool
{
    {
        const std::optional<Nyra::Process> process = Nyra::create_process(
        #ifdef lyrix_windows
        "powershell.exe", std::vector<std::string>{"-Command", "New-Item", "-ItemType", "Directory"
        , "-Name", "\"nya\""}
        #else
        "/bin/mkdir", std::vector<std::string>{"nya"}
        #endif
        );
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