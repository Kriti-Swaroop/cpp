#pragma once

enum Flags
{
	/*
	 * All bits on the LHS are shifted left
	 * by RHS amount of numbers. EXAMPLE:
	 *
	 * 7 = 0111, so 7 << 1 is 1110
	 *
	 */
	flag1 = 1 << 0,		// bit  0
	flag2 = 1 << 1,		// bit  1
	flag3 = 1 << 2,		// bit  2
	flag4 = 1 << 3,		// bit  3
	flag5 = 1 << 4,		// bit  4
	flag6 = 1 << 5,		// bit  5
	flag7 = 1 << 6,		// bit  6
	flag8 = 1 << 7,		// bit  7
	flag9 = 1 << 8,		// bit  8
	flag10 = 1 << 9,	// bit  9
	flag11 = 1 << 10,	// bit 10
	flag12 = 1 << 11,	// bit 11
	flag13 = 1 << 12,	// bit 12
	flag14 = 1 << 13,	// bit 13
	flag15 = 1 << 14,	// bit 14
	flag16 = 1 << 15,	// bit 15
	flag17 = 1 << 16,	// bit 16
	flag18 = 1 << 17,	// bit 17
	flag19 = 1 << 18,	// bit 18
	flag20 = 1 << 19,	// bit 19
	flag21 = 1 << 20,	// bit 20
	flag22 = 1 << 21,	// bit 21
	flag23 = 1 << 22,	// bit 22
	flag24 = 1 << 23,	// bit 23
	flag25 = 1 << 24,	// bit 24
	flag26 = 1 << 25,	// bit 25
	flag27 = 1 << 26,	// bit 26
	flag28 = 1 << 27,	// bit 27
	flag29 = 1 << 28,	// bit 28
	flag30 = 1 << 29,	// bit 29
	flag31 = 1 << 30	// bit 31
};

bool test(std::uint32_t& number, const Flags& flag);
void set(std::uint32_t& number, const Flags& flag);
void reset(std::uint32_t& number, const Flags& flag);
void flip(std::uint32_t& number, const Flags& flag);