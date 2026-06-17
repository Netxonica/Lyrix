// Copyright 2026 Netxonica. All Rights Reserved.
#if lyrix_major >= 0 and lyrix_middle >= 0 and lyrix_minor >= 1
#ifndef lyrix_header_guard_nyra_character_sets
#define lyrix_header_guard_nyra_character_sets

#define $lyrix_uppercase 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H'\
: case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case \
'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z'
#define $lyrix_lowercase 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h'\
: case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case \
'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z'
#define $lyrix_alpha $lyrix_uppercase: case $lyrix_lowercase
#define $lyrix_digit_non_zero '1': case '2': case '3': case '4': case '5': case '6': case '7': \
case '8': case '9'
#define $lyrix_digit '0': case $lyrix_digit_non_zero
#define $lyrix_alphanumeric $lyrix_digit: case $lyrix_alpha

#endif
#endif