#include <cstdint>
#include "flag.hpp"

// NOTE: All truthtables alias A to number and B to flag.
// The relevant rows are encompass by '> <', the other rows
// are there for the sake for completeness.

bool test(std::uint_fast32_t& number, const Flags& flag)
{
	/*
	 * |---|---|-----| EXPLANATION: returns 'W'
	 * | A | B | AND | if both bits are turned
	 * |---|---|-----| on, meaning this flag is
	 * | W | W |> W <| enabled, else 'F' (flag
	 * | W | F |  F  | is disabled).
	 * | F | W |> F <|
	 * | F | F |  F  |
	 * |---|---|-----|
	 */
	return (number & flag);
}

void set(std::uint_fast32_t& number, const Flags& flag)
{
	/*
	 * |---|---|-----| EXPLANATION: returns 'W'
	 * | A | B |  OR | if at least one bit is
	 * |---|---|-----| turned on. The assignment
	 * | W | W |> W <| operator |= is a shorthand
	 * | W | F |  W  | notation for A = ( A | B ),
	 * | F | W |> W <| meaning A will be assigned
	 * | F | F |  F  | the result of this comparison.
	 * |---|---|-----| The sets a bit because the
	 *                 result is always 'W'.
	 */
	number |= flag;
}

void reset(std::uint_fast32_t& number, const Flags& flag)
{
	/*
	 * |---|---|------| EXPLANATION: Here, &=~
	 * | A | B | ~AND | is a shorthand notation
	 * |---|---|------| for A = ( A & ~B ) which
	 * | W | W | > F <| is equivalent to the negated
	 * | W | F |   W  | AND assigmnet. This unsets
	 * | F | W | > F <| a bit because the result is
	 * | F | F |   F  | always 'F'.
	 * |---|---|------| 
	 *                 
	 */
	number &= ~flag;
}

void flip(std::uint_fast32_t& number, const Flags& flag)
{
	/*
	 * |---|---|------| EXPLANATION: Here, ^
	 * | A | B |  XOR | is a shorthand notation
	 * |---|---|------| for A = ( A ^ B ) which
	 * | W | W | > F <| assigns the A XOR B to A.
	 * | W | F |   W  | From the truthtable it
	 * | F | W | > W <| becomes evident why this
	 * | F | F |   F  | flip the states of bits
	 * |---|---|------| to their counterparts.
	 *
	 */
	number ^= flag;
}