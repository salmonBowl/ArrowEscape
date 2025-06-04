#pragma once
#include <memory>
#include <map>

enum class AllGraphName
{
	Player,
	Background,
	Frontground,
	Arrow,
	Beam
};

class Image
{
public:

	static std::shared_ptr<Image> Instance();


	int LoadGraph(const char* fileName, float magnification);

private:
	
	static std::shared_ptr<Image> instance;

	std::map<AllGraphName, int> generateData;
};