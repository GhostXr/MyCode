#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "vector"
#include "string"
#include "set"
#include "algorithm"
#include "functional"
#include "numeric"
#include "map"
#include "deque"

using namespace std;

class Speaker
{
public:
	void setName(string name)
	{
		this->name = name;
	}
	void printSpeaker()
	{
		cout<<"name = "<<this->name<<endl;
	}
public:
	string name;
	int score[3];
};

int GenSpeaker(map<int, Speaker> &mapspeaker, vector<int> &v1)
{
	string str = "ABCDEFGHIGKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());

	for(int i = 0; i <24; i++)
	{
		Speaker temp;
		temp.name = "选手";
		temp.name = temp.name+str[i];
		mapspeaker.insert(pair<int, Speaker>(100+i, temp));
	}

	for(int i = 0; i < 24; i++)
	{
		v1.push_back(100+i);
	}
	return 1;
}

int speakerNumber( vector<int> &v1)
{
	random_shuffle(v1.begin(), v1.end());
	return 1;
}

int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapspeaker, vector<int> &v2)
{

	multimap<int, int, greater<int>> map; 
	int tmpCount = 0;

	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		//打分
		deque<int> dscore;
		for(int i = 0; i <10; i++)
		{
			int temp = 50+rand()%50;
			dscore.push_back(temp);
		}
		sort(dscore.begin(), dscore.end());
		dscore.pop_back();
		dscore.pop_front();
		
		//求平均分
		int sum = accumulate(dscore.begin(), dscore.end(), 0);
		sum = sum/dscore.size();

		mapspeaker[*it].score[index] = sum;

		//记录小组得分
		map.insert(pair<int, int>(sum, *it));
		
		tmpCount++;
		if (tmpCount%6 == 0)
		{
			cout<<"小组的比赛成绩"<<endl;
			for(multimap<int, int, greater<int>>::iterator mit = map.begin(); mit != map.end(); mit++)
			{
				cout<<"编号："<<mit->second<<" "<<"姓名："<<mapspeaker[mit->second].name<<" "<<"成绩："<<mit->first<<endl;
			}

			//前三名晋级
			while (map.size() > 3)
			{
				multimap<int, int, greater<int>>::iterator mit1 = map.begin();
				v2.push_back(mit1->second);
				map.erase(mit1);
			}
			map.clear();
		}
	}
	return 0;
}

int speech_contest_print(int index, vector<int> &v1, map<int, Speaker> &mapspeaker)
{
	for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout<<"第"<<index+1<<"轮晋级的是"<<*it<<endl;
	}
	return 1;
}

void main()
{
	map<int, Speaker> mapspeaker;  //选手

	vector<int>  v1; //第一轮结果
	vector<int>  v2; //第二轮结果
	vector<int>  v3; //第三轮结果
	vector<int>  v4; //最后前三名

	//产生选手， 第一轮分组
	GenSpeaker(mapspeaker, v1);

	//第一轮抽签，比赛，查看结果
	speakerNumber(v1);
	speech_contest(0, v1, mapspeaker, v2);
	speech_contest_print(0, v2, mapspeaker);

	
	//第二轮抽签，比赛，查看结果
	speakerNumber(v2);
	speech_contest(1, v2, mapspeaker, v3);
	speech_contest_print(1, v3, mapspeaker);
	
	//第三轮抽签，比赛，查看结果
	speakerNumber(v3);
	speech_contest(2, v3, mapspeaker, v4);
	speech_contest_print(2, v4, mapspeaker);

	system("pause");
	return;
}