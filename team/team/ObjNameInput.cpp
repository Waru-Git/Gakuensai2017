//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\DrawTexture.h"
#include "GameL\Audio.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjNameInput.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjNameInput::CObjNameInput(int rank)
{
	m_rank = rank;	//�����L���O
}

//�C�j�V�����C�Y
void CObjNameInput::Init()
{
	//�t���O�̏�����
	m_flag = false;
	m_input_count = 0;

	m_key_flag = true;

	for (int i = 0; i <= 6; i++)
		m_name[i] = ' ';//���p�󔒂ŏ�����

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"���O����͂��Ă�������(���p5�����ȓ�)\n");
}

//�A�N�V����
void CObjNameInput::Action()
{
	if (m_flag == true)	//2�T�ڈȍ~�ʂ�
	{
		while (m_input_count < 5)
		{
			if (m_key_flag == false) //�L�[�t���O���I�t�Ȃ�
			{
				//1�O�̕����Ɠ���������������Ă��Ȃ����
				if (Input::GetVKey(m_name[m_input_count - 1]) == false)
					m_key_flag = true;	//�L�[�t���O���I���ɂ���
			}

			if (m_key_flag == true)	//�L�[�t���O���I���Ȃ�
			{
				KeyInput(m_input_count);//���O�̓��͂�������
				m_key_flag=false;	//�L�[�t���O���I�t�ɂ���
			}
		}

		m_name[5] = '\0';//������\0�������

		strcpy(((UserData*)Save::GetData())->mRankingNameData[m_rank - 1], m_name);		//���O			
		
		Save::Seve();//UserData�̍쐬�i�Z�[�u�j����B


		//�^�C�g���V�[���Ɉړ�
		Scene::SetScene(new CSceneTitle());
	}
	m_flag = true;
}

//�h���[
void CObjNameInput::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�����̕`��
	Font::StrDraw(L"���O����͂��Ă�������(���p5�����ȓ�)\n", 340, 300, 60, c);
}

//�l�[�����͂̃L�[�{�[�h���當����ǂݎ��֐�
//����:���͂��ꂽ����������z��̗v�f��
void CObjNameInput::KeyInput(int number)
{
	//key�̏�Ԃ𒲂ׂ�
	for (char key = 'A'; key <= 'Z'; key++)
	{
		if (Input::GetVKey(key) == true)
		{
			m_name[number] = key;	//�����ꂽkey��z��ɕۑ�
			m_input_count++;		//�ۑ��ʒu���E�ɂ��炷
			break;
		}
	}
	//�o�b�N�X�y�[�X�������ꂽ�Ƃ�
	if (Input::GetVKey(VK_BACK) == true)
	{
		m_name[number] = ' ';	//�����ɂ��ǂ���
		m_input_count--;		//�ۑ��ʒu���ꕶ���O�ɂ��炷
	}
}
