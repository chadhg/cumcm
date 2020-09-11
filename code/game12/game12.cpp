// game12.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define _STD ::std::

enum class weather
{
	heat,
	serenity,
	sand,
};

//record the ligature situation
static const _STD vector<_STD vector<int>> map_one = {
	{},							 //0, mean nothing, ignore it.
	{2, 25},					 //1
	{1, 3},						 //2
	{2, 4, 25},					 //3
	{3, 5, 24, 25},				 //4
	{4, 6, 24},					 //5
	{5, 7, 23, 24},				 //6
	{6, 8, 22},					 //7
	{7, 9, 22},					 //8
	{8, 10, 15, 16, 17, 21, 22}, //9
	{9, 11, 13, 15},			 //10
	{10, 12, 13},				 //11
	{11, 13, 14},				 //12
	{10, 11, 12, 14, 15},		 //13
	{12, 13, 15, 16},			 //14
	{9, 10, 13, 14, 16},		 //15
	{9, 14, 15, 17, 18},		 //16
	{9, 16, 18, 21},			 //17
	{16, 17, 19, 20},			 //18
	{18, 20},					 //19
	{18, 19, 21},				 //20
	{9, 17, 20, 22, 23, 27},	 //21
	{7, 8, 9, 21, 23},			 //22
	{6, 21, 22, 24, 26},		 //23
	{4, 5, 6, 23, 25, 26},		 //24
	{1, 3, 4, 24, 26},			 //25
	{23, 24, 25, 27},			 //26
	{21, 26},					 //27
};

//record the ligature situation
static const _STD vector<_STD vector<int>> map_one_simple = {
	{},		  //0, mean nothing, ignore it.
	{25},	  //1
	{},		  //2
	{},		  //3
	{},		  //4
	{},		  //5
	{},		  //6
	{},		  //7
	{},		  //8
	{15, 21}, //9
	{},		  //10
	{},		  //11
	{14},	  //12
	{12},	  //13
	{15},	  //14
	{13, 9},  //15
	{},		  //16
	{},		  //17
	{},		  //18
	{},		  //19
	{},		  //20
	{27},	  //21
	{9},	  //22
	{22},	  //23
	{23},	  //24
	{24},	  //25
	{},		  //26
	{},		  //27
};

const _STD vector<int> map_one_village = {15};
const _STD vector<int> map_one_mine = {12};

const _STD vector<enum weather> map_weather = {
	weather::heat, // nothing

	weather::heat, // the first day
	weather::heat,
	weather::serenity,
	weather::sand,
	weather::serenity,
	weather::heat,
	weather::sand,
	weather::serenity,
	weather::heat,
	weather::heat,

	weather::sand,
	weather::heat,
	weather::serenity,
	weather::heat,
	weather::heat,
	weather::heat,
	weather::sand,
	weather::sand,
	weather::heat,
	weather::heat,

	weather::serenity,
	weather::serenity,
	weather::heat,
	weather::serenity,
	weather::sand,
	weather::heat,
	weather::serenity,
	weather::serenity,
	weather::heat,
	weather::heat,
};

int Dijkstra(int x, int y, int size)
{
	_STD vector<int> ans(size, 1000000);
	ans[x] = 0;
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (ans[j] == 1000000)
			{
				continue;
			}
			for (auto m : map_one[j])
			{
				if (ans[j] + 1 < ans[m])
				{
					ans[m] = ans[j] + 1;
				}
			}
		}
	}
	return ans[y];
}

void game(const _STD vector<int> &area, const _STD vector<int> &mine);
void calculate(int money, int water, int foods, const _STD vector<int> &area);

int main()
{
	_STD cout << "地图一中起点到采石场最短距离为："
			  << Dijkstra(1, 12, map_one.size()) << _STD endl;
	_STD cout << "地图一中采石场到终点最短距离为："
			  << Dijkstra(12, 27, map_one.size()) << _STD endl;
	_STD vector<_STD vector<int>> area_count = {
		//0  1   2   3   4   5  6  7  8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28 29  30
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14, 15, 9, 21, 27},
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 14, 15, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14, 15, 9, 21, 27},
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 12, 14, 15, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14, 15, 9, 21, 27},
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 12, 12, 14, 15, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14, 15, 9, 21, 27},
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 12, 12, 12, 14, 15, 13, 13, 13, 12, 12, 12, 12, 12, 12, 12, 14, 15, 9, 21, 27},
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 12, 12, 12, 12, 14, 15, 15, 15, 13, 12, 12, 12, 12, 12, 12, 14, 15, 9, 21, 27},
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 12, 12, 12, 12, 12, 14, 14, 14, 15, 13, 12, 12, 12, 12, 12, 14, 15, 9, 21, 27},
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14, 15, 13, 12, 12, 12, 12, 14, 15, 9, 21, 27},
		{1, 25, 24, 23, 23, 22, 9, 9, 15, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 14, 15, 13, 12, 12, 12, 14, 15, 9, 21, 27},
	};
	_STD cout << area_count[0].size() << _STD endl;
	for (auto area : area_count)
	{
		// calculate(4995, 99, 452, area);
		// _STD cout << _STD endl;
	}

}

class play
{
public:
	play(const _STD vector<_STD vector<int>> &map, const _STD vector<enum weather> &weather,
		 const _STD vector<int> &mine, const _STD vector<int> &village)
	{
		this->map = map;
		this->weather = weather;
		this->day = weather.size() - 1;
	}

	void dfs(int day, int area, int water, int foods, int money, _STD vector<int> a)
	{
		if (water < 0 || foods < 0 || money < 0)
		{
			return;
		}
		a.push_back(area);
		switch (map_weather[day])
		{
		case weather::heat:
			dfs(day + 1, area, water - 8, foods - 6, money, a);
			break;
		case weather::sand:
			dfs(day + 1, area, water - 10, foods - 10, money, a);
			break;
		case weather::serenity:
			dfs(day + 1, area, water - 5, foods - 7, money, a);
			break;
		default:
			break;
		}
		for (auto x : this->map[area])
		{
			if ([&]() -> bool {
					for (auto t : this->mine)
					{
						if (t == x)
						{
							return true;
						}
					}
					return false;
				}())
			{
				switch (map_weather[day])
				{
				case weather::heat:
					dfs(day + 1, area, water - 24, foods - 18, money + 1000, a);
					break;
				case weather::sand:
					dfs(day + 1, area, water - 30, foods - 30, money + 1000, a);
					break;
				case weather::serenity:
					dfs(day + 1, area, water - 15, foods - 21, money + 1000, a);
					break;
				default:
					break;
				}
			}
			else
			{
				switch (map_weather[day])
				{
				case weather::heat:

					break;

				case weather::sand:

					break;
				case weather::serenity:

					break;
				default:
					break;
				}
			}
		}
	}

	_STD vector<_STD vector<int>> map;
	_STD vector<enum weather> weather;
	_STD vector<int> mine;
	_STD vector<int> village;
	int day;
};

void calculate(int money, int water, int foods, const _STD vector<int> &area)
{
	for (int i = 1; i <= 30; ++i)
	{
		switch (map_weather[i])
		{
		case weather::heat:
			if (area[i] == 12)
			{
				// 开始挖矿
				if (area[i - 1] == 12)
				{
					water -= 8 * 3;
					foods -= 6 * 3;
					money += 1000;
				}
				else
				{
					water -= 8 * 2;
					foods -= 6 * 2;
				}
			}
			else
			{
				water -= 8 * 2;
				foods -= 6 * 2;
			}
			break;

		case weather::sand:
			if (area[i] == 12)
			{
				if (area[i - 1] == 12)
				{
					water -= 10 * 3;
					foods -= 10 * 3;
					money += 1000;
				}
				else
				{
					water -= 10;
					foods -= 10;
				}
			}
			else
			{
				water -= 10;
				foods -= 10;
			}
			break;

		case weather::serenity:
			if (area[i] == 12)
			{
				if (area[i - 1] == 12)
				{
					water -= 5 * 3;
					foods -= 7 * 3;
					money += 1000;
				}
				else
				{
					water -= 5 * 2;
					foods -= 7 * 2;
				}
			}
			else
			{
				water -= 5 * 2;
				foods -= 7 * 2;
			}
			break;

		default:
			break;
		}
		_STD cout << i << "water " << water << " foods " << foods << " money " << money
				  << _STD endl;
	}
	_STD cout << "最终结果为：" << money + water * 10 + foods * 20 << _STD endl;
}

void game(const _STD vector<int> &area, const _STD vector<int> &mine)
{
	int water = 0, foods = 0;
	for (int i = 1; i <= 30; ++i)
	{
		switch (map_weather[i])
		{
		case weather::heat:
			if (area[i] == 12)
			{
				if (area[i - 1] == 12)
				{
					water += 8 * 3;
					foods += 6 * 3;
				}
			}
			else
			{
				water += 8;
				foods += 6;
			}
			break;

		case weather::sand:
			if (area[i] == 12)
			{
				if (area[i - 1] == 12)
				{
					water += 10 * 3;
					foods += 10 * 3;
				}
			}
			else
			{
				water += 10;
				foods += 10;
			}
			break;

		case weather::serenity:
			if (area[i] == 12)
			{
				if (area[i - 1] == 12)
				{
					water += 5 * 3;
					foods += 7 * 3;
				}
			}
			else
			{
				water += 5;
				foods += 7;
			}
			break;

		default:
			break;
		}
	}
	_STD cout << "water needs :" << water
			  << "\nfoods needs :" << foods << _STD endl;
}
