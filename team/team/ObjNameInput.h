#pragma once

//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�l�[������
class CObjNameInput :public CObj
{
public:
	CObjNameInput() {};
	~CObjNameInput() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[

	void KeyInput(int number);//�l�[�����͂̃L�[�{�[�h���當����ǂݎ��֐�

private:
	char m_name[6];//���͂��ꂽ���O�̕ۑ��p
	bool m_flag;//�ŏ���1�񂩂ǂ����̔��f�p
	bool m_key_flag;//�L�[��������Ă��邩�ǂ����̃t���O
	int m_input_count;//���͂����񐔂̃J�E���^�[�B
};