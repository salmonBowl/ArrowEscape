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

// �l�b�g�ŏE���Ă����R�[�h
// LoadGraph�Ɋg��k���������֐�
int Image::LoadGraph(const char* FileName, float magnification) {

    int handle = DxLib::LoadGraph(FileName);//�摜�����[�h
    if (handle != -1) {//�摜�̃��[�h�ɐ��������ꍇ
        int SizeX, SizeY;//�摜�T�C�Y���i�[���邽�߂̕ϐ���p��
        GetGraphSize(handle, &SizeX, &SizeY);//���[�h�����摜�̃T�C�Y�擾
        int Nowscreen = GetDrawScreen();//���݂̕`��Ώۉ�ʂ��ꎞ�ۑ�
        SizeX = (int)(SizeX * magnification);//�g��{����������
        SizeY = (int)(SizeY * magnification);
        int minihandle = MakeScreen(SizeX, SizeY, TRUE);//�w��T�C�Y�̃O���t�B�b�N�n���h�����쐬
        if (minihandle == -1) {//�n���h���쐬�Ɏ��s�����ꍇ
            DeleteGraph(handle);//���������[�N���Ȃ��悤�ɁA�{���̃T�C�Y�̃O���t�B�b�N�n���h�����폜��return handle;�ɂ���Ζ{���̃T�C�Y�̂܂ܕԂ����Ƃ��ł��܂�
            return -1;//�G���[����������-1��Ԃ�
        }
        SetDrawScreen(minihandle);//�`��Ώۉ�ʂ��قǍ�����w��T�C�Y�̃O���t�B�b�N�n���h���ɕύX
        DrawExtendGraph(0, 0, SizeX, SizeY, handle, TRUE);//���[�h�����摜���w��T�C�Y�ŕ`��
        DeleteGraph(handle);//�s�v�ɂȂ����{���̃T�C�Y�̃O���t�B�b�N�n���h�����폜
        SetDrawScreen(Nowscreen);//���݂̕`��Ώۉ�ʂ����̉�ʂɖ߂�
        return minihandle;//�k�߂��摜�̃O���t�B�b�N�n���h����Ԃ�
    }
    else {//�摜�̃��[�h�Ɏ��s�����ꍇ
        return -1;//�G���[����������-1��Ԃ�
    }

}