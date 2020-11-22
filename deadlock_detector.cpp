// this is the ONLY file you should edit and submit to D2L

#include "common.h"

/// this is the function you need to implement
/// parameter lines[] contains a list of request and assignment edges
///   example of a request edge, process "p1" resource "r1"
///     "p1 -> r1"
///   example of an assignment edge, process "XYz" resource "XYz"
///     "XYz <- XYz"
/// Parameters deadlock_line_number and cycle[] are used to return
/// results back to the caller.
///
/// You need to process lines[] one edge at a time, and run a deadlock
/// detection after each edge.
///
/// As soon as you detecte a deadlock, you need to set deadlock_line_number to the index
/// in lines[] that caused the deadlock. For example, lines[7] caused the deadlock,
/// then set deadlock_line_number=7. You must also populete cycle[] with the names of
/// processes that are in a deadlock. You can then return from the function without
/// processing any other lines.
///
/// To indicate deadlock was detected after processing all lines, you must
/// set deadlock_line_number = -1 and clear cycle[] with cycle.clear()
///
void detect_deadlock(
    const std::vector<std::string>& lines, int& deadlock_line_number,
    std::vector<std::string>& cycle)
{
    cycle = split("A B C");
    deadlock_line_number = lines.size() / 10;
}
