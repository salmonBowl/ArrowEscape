#pragma once
#include <memory>
#include <map>
#include "Vector2.h"
#include "EnterValue.h"

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

	const GenerateInfo& GetInfo(ImageAssetID gameObject);
	void LoadIfNeeded(ImageAssetID gameObject); // ‹ŒLoadGraph

	void LoadAll();
	void ReleaseAll();

private:
	ImageManager();
	std::map<ImageAssetID, GenerateInfo> generateInfoMap;

	int LoadGraphInternal(ImageAssetID gameObject);

	static std::shared_ptr<ImageManager> instance;
};