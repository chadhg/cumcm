// game12.cpp
//

#include <iostream>
#include <vector>

#define _STD ::std::

enum class weather {
	heat,
	serenity,
	sand,
};

//record the ligature situation
static const _STD vector<_STD vector<int>> map_one = {
	{},                          //0, mean nothing, ignore it.
	{2, 25},                     //1
	{1, 3},                      //2
	{2, 4, 25},                  //3
	{3, 5, 24, 25},              //4
	{4, 6, 24},                  //5
	{5, 7, 23, 24},              //6
	{6, 8, 22},                  //7
	{7, 9, 22},                  //8
	{8, 10, 15, 16, 17, 21, 22}, //9
	{9, 11, 13, 15},             //10
	{10, 12, 13},                //11
	{11, 13, 14},                //12
	{10, 11, 12, 14, 15},        //13
	{12, 13, 15, 16},            //14
	{9, 10, 13, 14, 16},         //15
	{9, 14, 15, 17, 18},         //16
	{9, 16, 18, 21},             //17
	{16, 17, 19, 20},            //18
	{18, 20},                    //19
	{18, 19, 21},                //20
	{9, 17, 20, 22, 23, 27},     //21
	{7, 8, 9, 21, 23},           //22
	{6, 21, 22, 24, 26},         //23
	{4, 5, 6, 23, 25, 26},       //24
	{1, 3, 4, 24, 26},           //25
	{23, 24, 25, 27},            //26
	{21, 26},                    //27
};

const _STD vector<int> map_one_village = { 15 };
const  _STD vector<int> map_one_mine = { 12 };

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
	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (ans[j] == 1000000) {
				continue;
			}
			for (auto m : map_one[j]) {
				if (ans[j] + 1 < ans[m]) {
					ans[m] = ans[j] + 1;
				}
			}
		}
	}
	return ans[y];
}


int main()
{
	_STD cout << "地图一中起点到采石场最短距离为："
		<< Dijkstra(1, 12, map_one.size()) << _STD endl;
	_STD cout <<  "地图一中采石场到终点最短距离为："
		<< Dijkstra(12, 27, map_one.size()) << _STD endl;

}
