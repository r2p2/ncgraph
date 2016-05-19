#include <ncurses.h>
#include <vector>
#include <algorithm>

#include <iostream>
#include <string>
int main()
{
	std::vector<double> values;

	initscr();
	curs_set(0);

	std::string line;
	while (std::getline(std::cin, line))
	{
		if (line == "quit")
			break;

		values.push_back(std::stod(line));

		int winh = LINES;
		int winw = COLS;
		getmaxyx(stdscr, winh, winw);
		clear();

		auto start = values.cend();
		for (size_t i = 0; i < winw and start != values.cbegin(); ++i, --start);
		auto const min_value = *std::min_element(start, values.cend());
		auto const max_value = *std::max_element(start, values.cend());
		auto const dif_value = max_value - min_value;

		auto it = start;
		for (int x = 0; x < winw and it != values.cend(); ++x, ++it)
		{
			double const y = *it;
			double const y_value = (y-min_value)/(max_value-min_value);
			double const y_rel = (static_cast<double>(winh)*y_value);

			mvprintw(0, 0, std::string("x: " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(y_value) + " " + std::to_string(y_rel)).c_str());
			mvprintw(winh-static_cast<int>(y_rel), x, "*");
		}
		refresh();
	}
	getch();
	endwin();

	return 0;
}
