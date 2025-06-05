#include "ImageManager.h"

#include "DxLib.h"

std::shared_ptr<ImageManager> ImageManager::instance = nullptr;

std::shared_ptr<ImageManager> ImageManager::Instance()
{
    if (!instance)
    {
        instance = std::shared_ptr<ImageManager>(new ImageManager());
    }
    return instance;
}

ImageManager::ImageManager()
{
    generateInfoMap = 
    {
        { ImageAssetID::PlayerImage, { -1, "../res/player.png", 1.0f, Vector2{89, 96} } },
        { ImageAssetID::BackgroundImage, { -1, "../res/background.png", 3.0f, Vector2{768, 768} } },
        { ImageAssetID::ArrowImage, { -1, "../res/arrow.png", 1.0f, Vector2{ 89, 96 } } }
    };
}

// 
const ImageManager::GenerateInfo& ImageManager::GetInfo(ImageAssetID name)
{
    return generateInfoMap.at(name);
}
void ImageManager::LoadIfNeeded(ImageAssetID name)
{
    auto& info = generateInfoMap.at(name);
    if (info.handle == -1)
    {
        info.handle = LoadGraphInternal(name);
    }
}

int ImageManager::LoadGraphInternal(ImageAssetID name)
{
    int handle = DxLib::LoadGraph(generateInfoMap[name].fileName);//画像をロード
    if (handle != -1) {//画像のロードに成功した場合
        int SizeX, SizeY;//画像サイズを格納するための変数を用意
        GetGraphSize(handle, &SizeX, &SizeY);//ロードした画像のサイズ取得
        int Nowscreen = GetDrawScreen();//現在の描画対象画面を一時保存
        float magnification = generateInfoMap[name].magnification;
        SizeX = (int)(SizeX * magnification);//拡大倍率をかける
        SizeY = (int)(SizeY * magnification);
        int minihandle = MakeScreen(SizeX, SizeY, TRUE);//指定サイズのグラフィックハンドルを作成
        if (minihandle == -1) {//ハンドル作成に失敗した場合
            DeleteGraph(handle);//メモリリークしないように、本来のサイズのグラフィックハンドルを削除※return handle;にすれば本来のサイズのまま返すこともできます
            printf("拡縮した画像の作成に失敗しました\n");
            return -1;
        }
        SetDrawScreen(minihandle);//描画対象画面を先ほど作った指定サイズのグラフィックハンドルに変更
        DrawExtendGraph(0, 0, SizeX, SizeY, handle, TRUE);//ロードした画像を指定サイズで描画
        DeleteGraph(handle);//不要になった本来のサイズのグラフィックハンドルを削除
        SetDrawScreen(Nowscreen);//現在の描画対象画面を元の画面に戻す
        return minihandle;//縮めた画像のグラフィックハンドルを返す
    }
    else {//画像のロードに失敗した場合
        printf("画像の読み込みに失敗しました\n");
        return -1; //エラー発生を示す-1を返す
    }
}

void ImageManager::LoadAll()
{
    for (auto& generateInfo : generateInfoMap)
    {
        int& handle = generateInfo.second.handle;
        ImageAssetID name = generateInfo.first;
        if (handle == -1)
        {
            handle = LoadGraphInternal(name);
        }
    }
}
void ImageManager::ReleaseAll()
{
    // 画像リソース開放
    for (auto& generateInfo : generateInfoMap)
    {
        int& handle = generateInfo.second.handle;
        if (handle != -1)
        {
            DeleteGraph(handle);
            handle = -1; // AIに見つけてもらって追記
        }
    }
}
