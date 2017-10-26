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

//�R���X�g���N�^
CObjRanking::CObjRanking(int rank)
{
	m_rank = rank; //�����Ă������ʂ�ۑ�
}

//�C�j�V�����C�Y
void CObjRanking::Init()
{
	m_key_flag = false;//�L�[�t���O

	for (int i = 0; i <= 10; i++)
	{
		//���Ԃɏ����l9999�������Ă����ꍇtrue
		if (((UserData*)Save::GetData())->mRankingTimeData[i] == SET_TIME)
		{
			time_set_flag[i] = true;
		}
	}
}

//�A�N�V����
void CObjRanking::Action()
{
	//�G���^�[�L�[�������ꂽ��
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			if (m_rank <= 10)	//10�ʈȓ��Ȃ�
			{
				//���O���̓V�[���ֈړ�
				Scene::SetScene(new CSceneNameInput(m_rank));
			}
			else//�����L���O�O�Ȃ�
			{
				//���[�h�Z���N�g��
				CObjModeChoice* obj = new CObjModeChoice();
				Objs::InsertObj(obj, OBJ_MODE_CHOICE, 10);

				m_key_flag = false;

				this->SetStatus(false);//�����L���O�j��
			}
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
	wchar_t str_time[256];

	//�����L���O
	Font::StrDraw(L"�����L���O",350,30,60,c);

	int j;

	//�����N�擾��10�ʈȏ�Ȃ�11�ʕ\�������Ȃ�
	if (m_rank > 10)
		j = 10;
	else
		j = 9;

	for (int i = 0; i <= j; i++)
	{
		//�^�C���\��-----------------------------------------------
		//�����l9999�������Ă���ꍇ
		if (time_set_flag[i] == true)
		{
			if (j == 9)
			{
				swprintf_s(str_time, L"%2d��     --:--", i + 1);
				Font::StrDraw(str_time, 250, 130 + 55 * i, 40, c);
			}
			else if (j == 10 && i < 10)
			{
				swprintf_s(str_time, L"%2d��     --:--", i + 1);
				Font::StrDraw(str_time, 250, 130 + 55 * i, 40, c);
			}
		}
		//�����l9999�������Ă��Ȃ��ꍇ
		else
		{
			if (j == 9)//10�ʈȏ�Ȃ�11�ʕ\�����Ȃ�
			{
				swprintf_s(str_time, L"%2d��     %02d:%02d", i + 1, ((UserData*)Save::GetData())->mRankingTimeData[i] / 60, ((UserData*)Save::GetData())->mRankingTimeData[i] % 60);
				Font::StrDraw(str_time, 250, 130 + 55 * i, 40, c);
			}
			else if (j == 10 && i == 10)//10�ʈȉ��Ȃ�11�ʕ\��
			{
				swprintf_s(str_time, L"         %02d:%02d",((UserData*)Save::GetData())->mRankingTimeData[i] / 60, ((UserData*)Save::GetData())->mRankingTimeData[i] % 60);
				Font::StrDraw(str_time, 225, 140 + 55 * i, 45, c);
			}
			else if (j == 10 && i < 10)//1�`10�ʕ\��
			{
				swprintf_s(str_time, L"%2d��     %02d:%02d", i + 1, ((UserData*)Save::GetData())->mRankingTimeData[i] / 60, ((UserData*)Save::GetData())->mRankingTimeData[i] % 60);
				Font::StrDraw(str_time, 250, 130 + 55 * i, 40, c);
			}
			
		}
	}
	//-----------------------------------------------------------------------------

	//���O�\��----------------------------------------
	for (int i = 0; i < 10; i++)
	{
		wchar_t str_name[256];
		char name[6];
		strcpy(name, ((UserData*)Save::GetData())->mRankingNameData[i]);

		mbstowcs(str_name, name, 12);	//char ����wchar_t�@�Ɂ@�w�肵���T�C�Y���R�s�[

		Font::StrDraw(str_name, 660, 130 + 55 * i, 40, c);
	}
	//-------------------------------------------------
}