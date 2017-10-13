//�g�p����w�b�_�[
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include"GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\Audio.h"

#include "GameHead.h"
#include "ObjGameOver.h"
#include "ObjBackground.h"

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