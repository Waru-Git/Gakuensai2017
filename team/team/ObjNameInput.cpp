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

//�C�j�V�����C�Y
void CObjNameInput::Init()
{
	//�t���O�̏�����
	m_flag = false;

	for (int i = 0; i <= 6; i++)
		m_name[i] = ' ';//���p�󔒂ŏ�����

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"���O����͂��Ă�������(���p5�����ȓ�)\n");
}

//�A�N�V����
void CObjNameInput::Action()
{
	m_flag = KeyInput();//���O����͂�����֐�

	if (m_flag == true)	//���O���͂��I��������
	{
		//�^�C�g���V�[���Ɉړ�
		Scene::SetScene(new CSceneTitle());
	}
}

//�h���[
void CObjNameInput::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�����̕`��
	Font::StrDraw(L"���O����͂��Ă�������(���p5�����ȓ�)\n", 340, 300, 60, c);
}

//�l�[�����͂̃L�[�{�[�h���當����ǂݎ��֐�
bool CObjNameInput::KeyInput()
{
	int i = 0;
	
	//while (i < 6)
	//{
		//key�̏�Ԃ𒲂ׂ�
		for (char key = 'A'; key <= 'Z'; key++)
		{
			if (Input::GetVKey(key) == true)
			{
				m_name[i++] = key;	//�����ꂽkey��z��ɕۑ�
				break;				//���[�v�𔲂���
			}
		}
		
		//�o�b�N�X�y�[�X�������ꂽ�Ƃ�
		if (Input::GetVKey(VK_BACK) == true)
		{
			m_name[i] = ' ';//�����ɂ��ǂ���
			i--;	//�ۑ��ʒu���ꕶ���O�ɂ��炷
		}
	//}
		if (m_name[5] != ' ')
			return true;

	return false;
}
