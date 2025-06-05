#pragma once
#include <memory>
#include <map>
#include "Vector2.h"

enum class AllGraphName
{
	Player,
	Background,
	Frontground,
	Arrow,
	Beam
};

class ImageManager
{
public:

	static std::shared_ptr<ImageManager> Instance();

	struct GenerateInfo
	{
		int handle = -1;
		const char* fileName = "";
		const float magnification = 1.0f;
		const Vector2 offset = { };
	};

	GenerateInfo& GetInfo(AllGraphName gameObject);

	void LoadAll();
	void ReleaseAll();

private:
	ImageManager();
	static std::shared_ptr<ImageManager> instance;

	int LoadGraph(AllGraphName gameObject);

	std::map<AllGraphName, GenerateInfo> generateInfoMap;
};