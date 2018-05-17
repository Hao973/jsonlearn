//testjson.cpp
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "./json/json.h"

using namespace std;

bool ParseJsonFromFile(const char* filename);

int main()
{
	if(!ParseJsonFromFile("./data/test.json")){
		printf("ParseJsonFromFile error.\n");
		return 0;
	}
	return 0;
}

bool ParseJsonFromFile(const char* filename)
{    
	Json::Reader reader;      
	Json::Value root;           

	std::ifstream is;
	is.open(filename);
	
	if (reader.parse(is, root))	 
	{
		int 	i_apt = root["i_apt"].asInt();
		string  str_ip = root["str_ip"].asString();
		printf("i_apt:%d, str_ip:%s\n", i_apt, str_ip.c_str());
		
		//adplaces
		Json::Value adplaces = root["adplaces"];
		int adp_size = adplaces.size();
		printf("adp_size: %d\n", adp_size);
		for( int i=0; i<adp_size; i++){
			string str_itemspaceid = adplaces[i]["str_itemspaceid"].asString();
			int i_width = adplaces[i]["i_width"].asInt();
			int i_height = adplaces[i]["i_height"].asInt();
			printf("adplaces[%d] str_itemspaceid=%s, i_width=%d, i_height=%d\n",
					i, str_itemspaceid.c_str(), i_width, i_height);
		}
		
	}else{
		printf("reader.parse() error.\n");
		is.close();
		return false;
	}
	is.close();
	return true;
}