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

	//name�̏�����
	for (int i = 0; i < 5; i++)
	{
		m_name[i] = '-';
	}

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"���O����͂��Ă�������(���p5�����ȓ�)\n");
}

//�A�N�V����
void CObjNameInput::Action()
{


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