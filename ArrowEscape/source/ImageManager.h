#pragma once
#include <memory>
#include <unordered_map>
#include "Vector2.h"
#include "EnterValue.h"
#include "SingletonBase.h"

class ImageManager : public SingletonBase<ImageManager>
{
	friend class SingletonBase<ImageManager>;
public:
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
	std::unordered_map<ImageAssetID, GenerateInfo> generateInfoMap;

	int LoadGraphInternal(ImageAssetID gameObject);
};