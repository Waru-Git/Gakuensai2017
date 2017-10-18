//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include"GameL\DrawTexture.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjRanking.h"
#include"ObjBackground.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjRanking::Init()
{
	m_key_flag = false;//�L�[�t���O

	//�N������񂾂������L���O������
	static bool init_point = false;
	if (init_point == false)
	{
		//�����L���O������
		for (int i = 0; i < 10; i++)
		{
			((UserData*)Save::GetData())->mRankingTimeData[i] = 0;
		}
		init_point = true;
	}
}

//�A�N�V����
void CObjRanking::Action()
{
	//�G���^�[�L�[�������ꂽ�烂�[�h�Z���N�g�֖߂�
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			CObjModeChoice* obj = new CObjModeChoice();
			Objs::InsertObj(obj, OBJ_MODE_CHOICE, 10);

			m_key_flag = false;

			this->SetStatus(false);//�����L���O�j��
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjRanking::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�����L���O
	Font::StrDraw(L"�����L���O",350,30,60,c);

	for (int i = 0; i < 10; i++)
	{
		wchar_t str[256];
		swprintf_s(str, L"%2d��    %02d:%02d", i + 1, ((UserData*)Save::GetData())->mRankingTimeData[i]/60,((UserData*)Save::GetData())->mRankingTimeData[i]%60);
		Font::StrDraw(str, 350, 150 + 60 * i,40,c);
	}
}