// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#include "Eura/Json.hpp"
#include <charconv>
#include "Eura/Lexer.hpp"
#include "Nyra/CharacterSets.hpp"
#define $json_whitespace '\t': case '\n': case '\r': case ' '
#define $json_hexadecimal 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'a': case \
'b': case 'c': case 'd': case 'e': case 'f'

namespace Eura::Json
{
    [[nodiscard]] static auto Categorize(const std::string_view content) noexcept -> Type
    {
        enum class [[nodiscard]] Context : std::uint8_t
        {
            General = 0u,
            Negative = 1u,
            Zero = 2u,
            CInteger = 3u,
            Point = 4u,
            Exponent_e = 5u,
            Fraction = 6u,
            Exponent_sign = 7u,
            Exponent = 8u
        };
        Type type;
        using enum Context;
        Context mode = General;
        for(const char character : content)
            switch(mode)
            {
                using enum Type;
                case General:
                    switch(character)
                    {
                        case '-':
                            mode = Negative;
                            type = Integer;
                        break;
                        case '0':
                            mode = Zero;
                            type = Natural;
                        break;
                        case $lyrix_digit_non_zero:
                            mode = CInteger;
                            type = Natural;
                        break;
                        default:
                            std::abort();
                    }
                break;
                case Negative:
                    switch(character)
                    {
                        case '0':
                            mode = Zero;
                        break;
                        case $lyrix_digit_non_zero:
                            mode = CInteger;
                        break;
                        default:
                            std::abort();
                    }
                break;
                case Zero:
                    switch(character)
                    {
                        case '.':
                            mode = Point;
                        break;
                        case 'E':
                        case 'e':
                            mode = Exponent_e;
                        break;
                        default:
                            std::abort();
                    }
                    type = Real;
                break;
                case CInteger:
                    switch(character)
                    {
                        case $lyrix_digit:
                        break;
                        case '.':
                            mode = Point;
                            type = Real;
                        break;
                        case 'E':
                        case 'e':
                            mode = Exponent_e;
                            type = Real;
                        break;
                        default:
                            std::abort();
                    }
                break;
                case Point:
                    switch(character)
                    {
                        case $lyrix_digit:
                            mode = Fraction;
                        break;
                        default:
                            std::abort();
                    }
                break;
                case Fraction:
                    switch(character)
                    {
                        case $lyrix_digit:
                        break;
                        case 'E':
                        case 'e':
                            mode = Exponent_e;
                        break;
                        default:
                            std::abort();
                    }
                break;
                case Exponent_e:
                    switch(character)
                    {
                        case '+':
                        case '-':
                            mode = Exponent_sign;
                        break;
                        case $lyrix_digit:
                            mode = Exponent;
                        break;
                        default:
                            std::abort();
                    }
                break;
                case Exponent_sign:
                    switch(character)
                    {
                        case $lyrix_digit:
                            mode = Exponent;
                        break;
                        default:
                            std::abort();
                    }
                break;
                case Exponent:
                    switch(character)
                    {
                        case $lyrix_digit:
                        break;
                        default:
                            std::abort();
                    }
            }
        switch(mode)
        {
            default:
                std::abort();
            case Zero:
            case CInteger:
            case Fraction:
            case Exponent:
                return type;
        }
    }

    enum class [[nodiscard]] Context : std::uint8_t
    {
        Root = 0u,
        EndRoot = 1u,
        Name = 2u,
        Colon = 3u,
        Value = 4u,
        Comma = 5u
    };

    [[nodiscard]] static auto DeserializeObject(std::size_t& id, const Lexer& lexer, Strings&
    strings) noexcept -> Object;

    [[nodiscard]] static auto DeserializeArray(std::size_t& id, const Lexer& lexer, Strings&
    strings) noexcept -> Array
    {
        Array array;
        using enum Context;
        Context context = Root;
        for(; id < lexer.tokens.size(); ++id)
        {
            const Token& token = lexer.tokens[id];
            switch(context)
            {
                default:
                break;
                case Root:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::EndArray:
                            return array;
                        case Type::Null:
                            array.emplace_back(Null{});
                        break;
                        case Type::False:
                            array.emplace_back(Boolean{false});
                        break;
                        case Type::True:
                            array.emplace_back(Boolean{true});
                        break;
                        case Type::Natural:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Uinteger output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            array.emplace_back(output);
                        }
                        break;
                        case Type::Integer:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Integer output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            array.emplace_back(output);
                        }
                        break;
                        case Type::Real:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Decimal output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            array.emplace_back(output);
                        }
                        break;
                        case Type::String:
                            array.emplace_back(token.Get(lexer.slices));
                        break;
                        case Type::MutatedString:
                            array.emplace_back(token.Get(strings));
                        break;
                        case Type::StartArray:
                            array.emplace_back(DeserializeArray(++id, lexer, strings));
                        break;
                        case Type::StartObject:
                            array.emplace_back(DeserializeObject(++id, lexer, strings));
                        break;
                    }
                    context = Comma;
                break;
                case Value:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::Null:
                            array.emplace_back(Null{});
                        break;
                        case Type::False:
                            array.emplace_back(Boolean{false});
                        break;
                        case Type::True:
                            array.emplace_back(Boolean{true});
                        break;
                        case Type::Natural:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Uinteger output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            array.emplace_back(output);
                        }
                        break;
                        case Type::Integer:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Integer output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            array.emplace_back(output);
                        }
                        break;
                        case Type::Real:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Decimal output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            array.emplace_back(output);
                        }
                        break;
                        case Type::String:
                            array.emplace_back(token.Get(lexer.slices));
                        break;
                        case Type::MutatedString:
                            array.emplace_back(token.Get(strings));
                        break;
                        case Type::StartArray:
                            array.emplace_back(DeserializeArray(++id, lexer, strings));
                        break;
                        case Type::StartObject:
                            array.emplace_back(DeserializeObject(++id, lexer, strings));
                        break;
                    }
                    context = Comma;
                break;
                case Comma:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::Comma:
                            context = Value;
                        break;
                        case Type::EndArray:
                            return array;
                    }
            }
        }
        std::abort();
    }

    [[nodiscard]] static auto DeserializeObject(std::size_t& id, const Lexer& lexer, Strings&
    strings) noexcept -> Object
    {
        Object object;
        using enum Context;
        Context context = Root;
        for(; id < lexer.tokens.size(); ++id)
        {
            const Token& token = lexer.tokens[id];
            switch(context)
            {
                default:
                break;
                case Root:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::String:
                            object.fields.emplace_back(token.Get(lexer.slices), Any{});
                        break;
                        case Type::MutatedString:
                            object.fields.emplace_back(token.Get(strings), Any{});
                        break;
                        case Type::EndObject:
                            return object;
                    }
                    context = Colon;
                break;
                case Name:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::String:
                            object.fields.emplace_back(token.Get(lexer.slices), Any{});
                        break;
                        case Type::MutatedString:
                            object.fields.emplace_back(token.Get(strings), Any{});
                    }
                    context = Colon;
                break;
                case Colon:
                    if(token.Get() not_eq Type::Colon)
                        std::abort();
                    context = Value;
                break;
                case Value:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::Null:
                            object.fields.back().second = Null{};
                        break;
                        case Type::False:
                            object.fields.back().second = Boolean{false};
                        break;
                        case Type::True:
                            object.fields.back().second = Boolean{true};
                        break;
                        case Type::Natural:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Uinteger output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            object.fields.back().second = output;
                        }
                        break;
                        case Type::Integer:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Integer output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            object.fields.back().second = output;
                        }
                        break;
                        case Type::Real:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Decimal output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            object.fields.back().second = output;
                        }
                        break;
                        case Type::String:
                            object.fields.back().second = token.Get(lexer.slices);
                        break;
                        case Type::MutatedString:
                            object.fields.back().second = token.Get(strings);
                        break;
                        case Type::StartArray:
                            object.fields.back().second = DeserializeArray(++id, lexer, strings);
                        break;
                        case Type::StartObject:
                            object.fields.back().second = DeserializeObject(++id, lexer, strings);
                        break;
                    }
                    context = Comma;
                break;
                case Comma:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::Comma:
                            context = Name;
                        break;
                        case Type::EndObject:
                            return object;
                    }
            }
        }
        std::abort();
    }

    // SAX-based, no error-handling (trust the LSP frontend producing at least correct JSON, else
    // simply abort and cope lol), so no need to track lines, columns, or other info regarding
    // tokens that could be useful for diagnostics
    [[nodiscard]] auto Deserialize(const std::string_view content, Strings& strings) noexcept ->
    Root
    {
        Lexer lexer;
        {
            auto PunctuationTokenize = [&](const Type type) noexcept
            {
                lexer.tokens.emplace_back(type);
            };
            auto CheckedPunctuationTokenize = [&](const std::size_t length, const Type type)
            noexcept
            {
                if(length)
                    std::abort();
                lexer.tokens.emplace_back(type);
            };
            auto KeywordNumericalTokenize = [&](std::size_t& length, const char* offset) noexcept
            {
                if(length)
                {
                    const std::string_view content(offset, length);
                    length = 0uz;
                    using enum Type;
                    const Type type = content == "null" ? Null : content == "true" ? True : content
                    == "false" ? False : Categorize(content);
                    if(type == Natural or type == Integer or type == Real)
                    {
                        lexer.tokens.emplace_back(type, lexer.slices.size());
                        lexer.slices.emplace_back(content);
                    }
                    else
                        lexer.tokens.emplace_back(type);
                }
            };
            std::string literal, hex;
            const char* offset;
            std::size_t length = 0uz;
            char first;
            bool mutated = false;
            enum class [[nodiscard]] Context : std::uint8_t
            {
                General = 0u,
                CString = 1u,
                Escape = 2u,
                Unicode = 3u
            };
            using enum Context;
            Context context = General;
            for(const char& character : content)
                switch(context)
                {
                    case General:
                        switch(character)
                        {
                            using enum Type;
                            default:
                                std::abort();
                            case $json_whitespace:
                            break;
                            case '+':
                            case '-':
                            case '.':
                            case $lyrix_digit:
                            case 'E':
                            case 'a':
                            case 'e':
                            case 'f':
                            case 'l':
                            case 'n':
                            case 'r':
                            case 's':
                            case 't':
                            case 'u':
                                if(length++ == 0uz)
                                    offset = &character;
                            break;
                            case '{':
                                CheckedPunctuationTokenize(length, StartObject);
                            break;
                            case '}':
                                KeywordNumericalTokenize(length, offset);
                                PunctuationTokenize(EndObject);
                            break;
                            case '[':
                                CheckedPunctuationTokenize(length, StartArray);
                            break;
                            case ']':
                                KeywordNumericalTokenize(length, offset);
                                PunctuationTokenize(EndArray);
                            break;
                            case ':':
                                CheckedPunctuationTokenize(length, Colon);
                            break;
                            case ',':
                                KeywordNumericalTokenize(length, offset);
                                PunctuationTokenize(Comma);
                            break;
                            case '"':
                                if(length)
                                    std::abort();
                                context = CString;
                        }
                    break;
                    case CString:
                        switch(character)
                        {
                            default:
                                if(mutated)
                                    literal.append(1uz, character);
                                else if(length++ == 0uz)
                                    offset = &character;
                            break;
                            case '"':
                                context = General;
                                if(mutated)
                                {
                                    mutated = false;
                                    lexer.tokens.emplace_back(Type::MutatedString, strings.size());
                                    strings.emplace_back(literal);
                                }
                                else
                                {
                                    lexer.tokens.emplace_back(Type::String, lexer.slices.size());
                                    lexer.slices.emplace_back(offset, length);
                                    length = 0uz;
                                }
                            break;
                            case '\\':
                                mutated = true;
                                context = Escape;
                                literal = std::string(offset, length);
                        }
                    break;
                    case Escape:
                        switch(character)
                        {
                            default:
                                std::abort();
                            case '"':
                                context = CString;
                                literal.append(1uz, '"');
                            break;
                            case '\\':
                                context = CString;
                                literal.append(1uz, '\\');
                            break;
                            case '/':
                                context = CString;
                                literal.append(1uz, '/');
                            break;
                            case 'b':
                                context = CString;
                                literal.append(1uz, '\b');
                            break;
                            case 'f':
                                context = CString;
                                literal.append(1uz, '\f');
                            break;
                            case 'n':
                                context = CString;
                                literal.append(1uz, '\n');
                            break;
                            case 'r':
                                context = CString;
                                literal.append(1uz, '\r');
                            break;
                            case 't':
                                context = CString;
                                literal.append(1uz, '\t');
                            break;
                            case 'u':
                                context = Unicode;
                        }
                    break;
                    case Unicode:
                        switch(character)
                        {
                            default:
                                std::abort();
                            case $lyrix_digit:
                            case $json_hexadecimal:
                                if(length == 1uz)
                                {
                                    ++length;
                                    hex.append(1uz, character);
                                    literal.append(1uz, first = static_cast<char>(std::stoi(hex,
                                    nullptr, 16)));
                                    hex.clear();
                                }
                                else if(length == 3uz)
                                {
                                    context = CString;
                                    length = 0uz;
                                    hex.append(1uz, character);
                                    const char second = static_cast<char>(std::stoi(hex, nullptr,
                                    16));
                                    const std::uint16_t codepoint = static_cast<std::uint16_t>(
                                    static_cast<unsigned char>(first) << 8u) bitor static_cast<
                                    unsigned char>(second);
                                    if(codepoint >= 0xD800 and codepoint <= 0xDFFF)
                                        std::abort();
                                    literal.append(1uz, second);
                                    hex.clear();
                                }
                                else
                                {
                                    ++length;
                                    hex.append(1uz, character);
                                }
                        }
                }
            switch(context)
            {
                default:
                    std::abort();
                case General:
                    if(length)
                        std::abort();
            }
        }
        strings.shrink_to_fit();
        lexer.slices.shrink_to_fit();
        lexer.tokens.shrink_to_fit();
        Root root;
        using enum Context;
        Context context = Root;
        for(std::size_t id = 0uz; id < lexer.tokens.size(); ++id)
        {
            const Token& token = lexer.tokens[id];
            switch(context)
            {
                case Root:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::StartObject:
                            context = Name;
                        break;
                        case Type::EndObject:
                            context = EndRoot;
                    }
                break;
                case EndRoot:
                    std::abort();
                case Name:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::String:
                            root.fields.emplace_back(token.Get(lexer.slices), Any{});
                        break;
                        case Type::MutatedString:
                            root.fields.emplace_back(token.Get(strings), Any{});
                    }
                    context = Colon;
                break;
                case Colon:
                    if(token.Get() not_eq Type::Colon)
                        std::abort();
                    context = Value;
                break;
                case Value:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::Null:
                            root.fields.back().second = Null{};
                        break;
                        case Type::False:
                            root.fields.back().second = Boolean{false};
                        break;
                        case Type::True:
                            root.fields.back().second = Boolean{true};
                        break;
                        case Type::Natural:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Uinteger output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            root.fields.back().second = output;
                        }
                        break;
                        case Type::Integer:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Integer output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            root.fields.back().second = output;
                        }
                        break;
                        case Type::Real:
                        {
                            const String& number = token.Get(lexer.slices);
                            const char* nend = number.data() + number.size();
                            Decimal output;
                            if(std::from_chars(number.data(), nend, output).ptr not_eq nend)
                                std::abort();
                            root.fields.back().second = output;
                        }
                        break;
                        case Type::String:
                            root.fields.back().second = token.Get(lexer.slices);
                        break;
                        case Type::MutatedString:
                            root.fields.back().second = token.Get(strings);
                        break;
                        case Type::StartArray:
                            root.fields.back().second = DeserializeArray(++id, lexer, strings);
                        break;
                        case Type::StartObject:
                            root.fields.back().second = DeserializeObject(++id, lexer, strings);
                        break;
                    }
                    context = Comma;
                break;
                case Comma:
                    switch(token.Get())
                    {
                        default:
                            std::abort();
                        case Type::Comma:
                            context = Name;
                        break;
                        case Type::EndObject:
                            context = EndRoot;
                    }
            }
        }
        if(context not_eq EndRoot)
            std::abort();
        return root;
    }

    static auto Serialize(std::string& content) noexcept -> void
    {
        content += "null";
    }

    static auto Serialize(const Boolean value, std::string& content) noexcept -> void
    {
        content += value ? "true" : "false";
    }

    static auto Serialize(const Uinteger value, std::string& content) noexcept -> void
    {
        constexpr std::size_t buffer_size = std::numeric_limits<Uinteger>::digits10 + 1uz;
        char buffer[buffer_size];
        content.append(buffer, std::to_chars(buffer, buffer + buffer_size, value).ptr);
    }

    static auto Serialize(const Integer value, std::string& content) noexcept -> void
    {
        constexpr std::size_t buffer_size = std::numeric_limits<Integer>::digits10 + 2uz;
        char buffer[buffer_size];
        content.append(buffer, std::to_chars(buffer, buffer + buffer_size, value).ptr);
    }

    static auto Serialize(const Decimal value, std::string& content) noexcept -> void
    {
        constexpr std::size_t buffer_size = 64uz;
        char buffer[buffer_size];
        content.append(buffer, std::to_chars(buffer, buffer + buffer_size, value).ptr);
    }

    static auto Serialize(const String value, std::string& content) noexcept -> void
    {
        content.append(1uz, '"');
        content += value;
        content.append(1uz, '"');
    }

    static auto Serialize(const Array& value, std::string& content) noexcept -> void;

    static auto Serialize(const Object& value, std::string& content) noexcept -> void
    {
        content.append(1uz, '{');
        for(const std::pair<String, Any>& field : value.fields)
        {
            content.append(1uz, '"');
            content += field.first;
            content += "\":";
            if(field.second.IsNull())
                Serialize(content);
            else if(field.second.IsBoolean())
                Serialize(field.second.As<Boolean>(), content);
            else if(field.second.IsUinteger())
                Serialize(field.second.As<Uinteger>(), content);
            else if(field.second.IsInteger())
                Serialize(field.second.As<Integer>(), content);
            else if(field.second.IsDecimal())
                Serialize(field.second.As<Decimal>(), content);
            else if(field.second.IsString())
                Serialize(field.second.As<String>(), content);
            else if(field.second.IsObject())
                Serialize(field.second.As<Object>(), content);
            else
                Serialize(field.second.As<Array>(), content);
            content.append(1uz, ',');
        }
        content.back() == ',' ? (void)(content.back() = '}') : (void)content.append(1uz, '}');
    }

    static auto Serialize(const Array& value, std::string& content) noexcept -> void
    {
        content.append(1uz, '[');
        for(const Any& field : value)
        {
            if(field.IsNull())
                Serialize(content);
            else if(field.IsBoolean())
                Serialize(field.As<Boolean>(), content);
            else if(field.IsUinteger())
                Serialize(field.As<Uinteger>(), content);
            else if(field.IsInteger())
                Serialize(field.As<Integer>(), content);
            else if(field.IsDecimal())
                Serialize(field.As<Decimal>(), content);
            else if(field.IsString())
                Serialize(field.As<String>(), content);
            else if(field.IsObject())
                Serialize(field.As<Object>(), content);
            else
                Serialize(field.As<Array>(), content);
            content.append(1uz, ',');
        }
        content.back() == ',' ? (void)(content.back() = ']') : (void)content.append(1uz, ']');
    }

    [[nodiscard]] auto Serialize(const Root& root) noexcept -> std::string
    {
        std::string content{1uz, '{'};
        for(const std::pair<String, Any>& field : root.fields)
        {
            content.append(1uz, '"');
            content += field.first;
            content += "\":";
            if(field.second.IsNull())
                Serialize(content);
            else if(field.second.IsBoolean())
                Serialize(field.second.As<Boolean>(), content);
            else if(field.second.IsUinteger())
                Serialize(field.second.As<Uinteger>(), content);
            else if(field.second.IsInteger())
                Serialize(field.second.As<Integer>(), content);
            else if(field.second.IsDecimal())
                Serialize(field.second.As<Decimal>(), content);
            else if(field.second.IsString())
                Serialize(field.second.As<String>(), content);
            else if(field.second.IsObject())
                Serialize(field.second.As<Object>(), content);
            else
                Serialize(field.second.As<Array>(), content);
            content.append(1uz, ',');
        }
        content.back() == ',' ? (void)(content.back() = '}') : (void)content.append(1uz, '}');
        return content;
    }
}

#endif