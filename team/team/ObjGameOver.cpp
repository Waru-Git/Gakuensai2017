//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjGameOver.h"
#include "ObjBackground.h"

#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�R���X�g���N�^
CObjGameOver::CObjGameOver(int p)
{
	m_pattern=p; //�Q�[�������p�^�[����ObjMain���玝���Ă��āAm_pattern�ɑ��
}

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	//�ʒu�̏�����
	m_y = 900.0f;
	m_yy = 800.0f;

	count=0;
	
	//CP�킩�ǂ�������ׂ�------
	//�}�b�v�I�u�W�F�N�g�̌Ăяo��
	CObjMain * obj = (CObjMain*)Objs::GetObj(OBJ_MAIN);
	m_cp_flag=obj->ReturnCPflag();
	//-------------------------

	//Win.wav�ȊO�̉��y���Ƃ߂�------
	//�퓬�ȃX�g�b�v
	Audio::Stop(8);
	//���s�~���[�W�b�N�J�n
	Audio::Start(7);
	//--------------------------------
}

//�A�N�V����
void CObjGameOver::Action()
{	
	count++;//�J�E���g�𑝂₵�Ă���

	if( count > 300)//300�𒴂��Ȃ��悤�ɂ���
		count = 300;

	//�G���^�[�L�[�������ꂽ��
	if(Input ::GetVKey(VK_RETURN)==true)
	{
		//�}�X�^�[�{�����[����1.0�ɖ߂�
		float v =Audio::VolumeMaster( 0 );
		v =Audio::VolumeMaster( (1.0-v) );

		//�^�C���v���������L���O�ۑ��V�X�e���̃f�o�b�O�p
		m_cp_flag = true;
		m_pattern = 1;
		//------------------------------------------

		//CP��@���@���v���C���[�̏����Ȃ�
		if (m_cp_flag == true && m_pattern == 1)
		{
			//�}�b�v�I�u�W�F�N�g�̌Ăяo��
			CObjMain * obj_main = (CObjMain*)Objs::GetObj(OBJ_MAIN);

			//�����L���O�̍ŉ��ʂɍ���̃^�C����ۑ�
			((UserData*)Save::GetData())->mRankingTimeData[10] = obj_main->ReturnTime();

			//�����L���O�̂��\�[�g����
			RankingSort(((UserData*)Save::GetData())->mRankingTimeData);

			Save::Seve();//UserData�̍쐬�i�Z�[�u�j����B
		}

		//�^�C�g���ֈڍs
		Scene::SetScene(new CSceneTitle);		
	}
}

//�h���[
void CObjGameOver::Draw()
{
	float c[4]={1.0f,1.0f,1.0f,1.0f};//�J���[
		
	Result();//���ʂ�\������
	Font::StrDraw(L"EnterKey�Ń^�C�g���ɖ߂�",223,m_y - count,50,c);
	
}

//�p�^�[���ɉ�����
void CObjGameOver::Result()
{
	CObjCP* obj_cp = new CObjCP();

	float c[4]={1.0f,1.0f,1.0f,1.0f};//�J���[
	
	switch(m_pattern)
	{
		case 0:
		{
			//���������\��
			Font::StrDraw(L"DROW",400,m_yy - count,100,c);
			break;
		}
		case 1:
		{
			if (obj_cp != nullptr)
			{
				//CPU����
				Font::StrDraw(L"YOU WIN", 350, m_yy - count, 100, c);
				break;
			}
			else//2�l�ΐ펞
			{
				//1Pwin�\��
				Font::StrDraw(L"1P WIN", 350, m_yy - count, 100, c);
				break;
			}
		}
		case 2:
		{
			if (obj_cp != nullptr)//CPU�ΐ킩�ۂ�����
			{
				//CPU����
				Font::StrDraw(L"YOU LOSE", 350, m_yy - count, 100, c);
				break;
			}
			else//2�l�ΐ펞
			{
				//2Pwin�\��
				Font::StrDraw(L"2P WIN", 350, m_yy - count, 100, c);
				break;
			}
		}
	}
}

//�����L���O�\�[�g���\�b�h
//�����Pint[11]:�����L���O�p�͔z��
//�Ⴂ���Ń\�[�g���s��
void CObjGameOver::RankingSort(int rank[11])
{
	//�l�̌����p�ϐ�
	int w;

	//�o�u���\�[�g
	for (int i = 0; i<10; i++)
	{
		for (int j = i + 1; j<11; j++)
		{
			if (rank[i] >= rank[j])
			{
				//�l�̌���
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;
			}
		}
	}
}
