#include "Image.h"

#include "DxLib.h"

std::shared_ptr<Image> Image::instance = nullptr;

std::shared_ptr<Image> Image::Instance()
{
    if (!instance)
    {
        instance = std::shared_ptr<Image>(new Image());
    }
    return instance;
}

// ネットで拾ってきたコード
// LoadGraphに拡大縮小をつけた関数
int Image::LoadGraph(const char* FileName, float magnification) {

    int handle = DxLib::LoadGraph(FileName);//画像をロード
    if (handle != -1) {//画像のロードに成功した場合
        int SizeX, SizeY;//画像サイズを格納するための変数を用意
        GetGraphSize(handle, &SizeX, &SizeY);//ロードした画像のサイズ取得
        int Nowscreen = GetDrawScreen();//現在の描画対象画面を一時保存
        SizeX = (int)(SizeX * magnification);//拡大倍率をかける
        SizeY = (int)(SizeY * magnification);
        int minihandle = MakeScreen(SizeX, SizeY, TRUE);//指定サイズのグラフィックハンドルを作成
        if (minihandle == -1) {//ハンドル作成に失敗した場合
            DeleteGraph(handle);//メモリリークしないように、本来のサイズのグラフィックハンドルを削除※return handle;にすれば本来のサイズのまま返すこともできます
            return -1;//エラー発生を示す-1を返す
        }
        SetDrawScreen(minihandle);//描画対象画面を先ほど作った指定サイズのグラフィックハンドルに変更
        DrawExtendGraph(0, 0, SizeX, SizeY, handle, TRUE);//ロードした画像を指定サイズで描画
        DeleteGraph(handle);//不要になった本来のサイズのグラフィックハンドルを削除
        SetDrawScreen(Nowscreen);//現在の描画対象画面を元の画面に戻す
        return minihandle;//縮めた画像のグラフィックハンドルを返す
    }
    else {//画像のロードに失敗した場合
        return -1;//エラー発生を示す-1を返す
    }

}