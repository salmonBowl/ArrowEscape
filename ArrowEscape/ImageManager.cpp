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
        { AllGraphName::Player, { -1, "player.png", 1.0f, Vector2{89, 96} } },
        { AllGraphName::Background, { -1, "background.png", 3.0f, Vector2{768, 768} } },
        { AllGraphName::Arrow, { -1, "arrow.png", 1.0f, Vector2{ 89, 96 } } }
    };
}

//
ImageManager::GenerateInfo& ImageManager::GetInfo(AllGraphName name)
{
    auto& info = generateInfoMap.at(name);
    if (info.handle == -1)
    {
        info.handle = ImageManager::LoadGraph(name);
    }
    return info;
}
int ImageManager::LoadGraph(AllGraphName name)
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
            return -1;
        }
        SetDrawScreen(minihandle);//�`��Ώۉ�ʂ��قǍ�����w��T�C�Y�̃O���t�B�b�N�n���h���ɕύX
        DrawExtendGraph(0, 0, SizeX, SizeY, handle, TRUE);//���[�h�����摜���w��T�C�Y�ŕ`��
        DeleteGraph(handle);//�s�v�ɂȂ����{���̃T�C�Y�̃O���t�B�b�N�n���h�����폜
        SetDrawScreen(Nowscreen);//���݂̕`��Ώۉ�ʂ����̉�ʂɖ߂�
        return minihandle;//�k�߂��摜�̃O���t�B�b�N�n���h����Ԃ�
    }
    else {//�摜�̃��[�h�Ɏ��s�����ꍇ
        return -1; //�G���[����������-1��Ԃ�
    }

}

void ImageManager::LoadAll()
{

}
void ImageManager::ReleaseAll()
{
    // �摜���\�[�X�J��
    for (auto& generateInfo : generateInfoMap)
    {
        int handle = generateInfo.second.handle;
        if (handle != -1)
        {
            DeleteGraph(handle);
        }
    }
}