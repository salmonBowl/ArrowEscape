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
    int handle = DxLib::LoadGraph(generateInfoMap[name].fileName);//�摜�����[�h
    if (handle != -1) {//�摜�̃��[�h�ɐ��������ꍇ
        int SizeX, SizeY;//�摜�T�C�Y���i�[���邽�߂̕ϐ���p��
        GetGraphSize(handle, &SizeX, &SizeY);//���[�h�����摜�̃T�C�Y�擾
        int Nowscreen = GetDrawScreen();//���݂̕`��Ώۉ�ʂ��ꎞ�ۑ�
        float magnification = generateInfoMap[name].magnification;
        SizeX = (int)(SizeX * magnification);//�g��{����������
        SizeY = (int)(SizeY * magnification);
        int minihandle = MakeScreen(SizeX, SizeY, TRUE);//�w��T�C�Y�̃O���t�B�b�N�n���h�����쐬
        if (minihandle == -1) {//�n���h���쐬�Ɏ��s�����ꍇ
            DeleteGraph(handle);//���������[�N���Ȃ��悤�ɁA�{���̃T�C�Y�̃O���t�B�b�N�n���h�����폜��return handle;�ɂ���Ζ{���̃T�C�Y�̂܂ܕԂ����Ƃ��ł��܂�
            printf("�g�k�����摜�̍쐬�Ɏ��s���܂���\n");
            return -1;
        }
        SetDrawScreen(minihandle);//�`��Ώۉ�ʂ��قǍ�����w��T�C�Y�̃O���t�B�b�N�n���h���ɕύX
        DrawExtendGraph(0, 0, SizeX, SizeY, handle, TRUE);//���[�h�����摜���w��T�C�Y�ŕ`��
        DeleteGraph(handle);//�s�v�ɂȂ����{���̃T�C�Y�̃O���t�B�b�N�n���h�����폜
        SetDrawScreen(Nowscreen);//���݂̕`��Ώۉ�ʂ����̉�ʂɖ߂�
        return minihandle;//�k�߂��摜�̃O���t�B�b�N�n���h����Ԃ�
    }
    else {//�摜�̃��[�h�Ɏ��s�����ꍇ
        printf("�摜�̓ǂݍ��݂Ɏ��s���܂���\n");
        return -1; //�G���[����������-1��Ԃ�
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
    // �摜���\�[�X�J��
    for (auto& generateInfo : generateInfoMap)
    {
        int& handle = generateInfo.second.handle;
        if (handle != -1)
        {
            DeleteGraph(handle);
            handle = -1; // AI�Ɍ����Ă�����ĒǋL
        }
    }
}
