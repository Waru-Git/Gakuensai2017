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
	m_first_flag = true;
	m_key_flag = false;		
	m_input_flag = false;
	m_end_flag = false;
	m_noname_flag = false;
	m_time_flag = true;
	

	//���O�p�z��̏�����
	for (int i = 0; i <= 6; i++)
		m_name[i] = ' ';//���p�󔒂ŏ�����
	
	//�R�s�[�p�z��̏�����
	for (int i = 0; i <= 10; i++)
		m_cpy_name[i] = ' ';//���p�󔒂ŏ�����

	m_time=0;//�_�ŗp�̃^�C���̏�����
	m_input_count = 0;//���O�ۑ��p�z��̗v�f�ԍ�������

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"���O����͂��Ă�������(�p��5�����ȓ�)");
	Font::SetStrTex(L"�Œ�1�����͓��͂��Ă�������"); 
	Font::SetStrTex(L"Enter�œ��͏I��");
	Font::SetStrTex(L"_");
}

//�A�N�V����
void CObjNameInput::Action()
{
	m_time++;//�_�ŗp�Ƀ^�C���𑝂₷

	if (m_time >= 10000)//10000�����������ɂȂ�����0�ɖ߂�
		m_time = 0;

	if (m_time % 60 == 0)//60f���ƂɃt���O�����ւ���
		m_time_flag = !(m_time_flag);

	//���߂�2��ڈȍ~
	if (m_first_flag == false)	
	{
		if(m_end_flag == false)	//���͂��I�����Ă��Ȃ����
		{
			if (m_key_flag == true)	//�L�[�t���O���I���Ȃ�
			{
				m_input_flag = KeyInput(m_input_count);//���O�̓��͂�������
				
				if (m_input_flag == true)//�Ή��{�^���̂ǂ����������ꂽ��
				{
					NameCpy(m_name);//�`��p�̃R�s�[���Ƃ�
					m_end_flag = InputEndCheck();//������̓��͂��I���Ă��邩�ǂ����𒲂ׂ�
					m_key_flag = false;	//�L�[�t���O���I�t�ɂ���
				}
			}
			else //�L�[�t���O���I�t�Ȃ�
			{
				//1�O�̕����Ɠ���������������Ă��Ȃ����
				if (Input::GetVKey(m_name[m_input_count - 1]) == false)
					m_key_flag = true;	//�L�[�t���O���I���ɂ���
			}

			//�f�o�b�O�p---------------------------------------
			wchar_t str[256];
			swprintf_s(str, L"m_input_count:%d", m_input_count);
			OutputDebugStringW(str);
			//--------------------------------------------------------
		}
		else		//���͂�����������
		{
			//���O�����[�U�[�f�[�^�ɃR�s�[
			strcpy(((UserData*)Save::GetData())->mRankingNameData[m_rank - 1], m_name);		//���O			

			Save::Seve();//UserData�̍쐬�i�Z�[�u�j����B
		
			//�^�C�g���V�[���Ɉړ�
			Scene::SetScene(new CSceneTitle());
		}
	}

	m_first_flag = false;

}

//�h���[
void CObjNameInput::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };	//�ʏ펞�̃J���[�i���j
	float c_red[4]{ 1.0f,0.0f,0.0f,1.0f };	//���ӕ��̃J���[�i�ԁj

	//�����̕`��
	Font::StrDraw(L"���O����͂��Ă�������(�p��5�����ȓ�)", 50.0f, 50.0f, 50.0f, c);
	Font::StrDraw(L"Enter�œ��͏I��",WINDOW_SIZE_W - 300.0f,WINDOW_SIZE_H - 50.0f,30.0f,c);

	wchar_t str_name[50];

	mbstowcs(str_name, m_cpy_name,sizeof(m_cpy_name)+1 );	//char ����wchar_t�@�Ɂ@�w�肵���T�C�Y���R�s�[
	
	Font::StrDraw(str_name, 200.0f, 200.0f, 50.0f, c);// ���͂���������\��

	//_�̕\��
	for (int i = 0; i < 5; i++)
	{
		if(i == m_input_count && m_time_flag == false)//���̓��͉ӏ� ���@�t���O�I�t�Ȃ�
			Font::StrDraw(L" ", 200.0f + 50.0f*i, 220.0f, 50.0f, c);// ' '��\��
		else
			Font::StrDraw(L"_", 200.0f + 50.0f*i, 220.0f, 50.0f, c);// '_'��\��
	}

	if(m_noname_flag == true)
		Font::StrDraw(L"�Œ�1�����͓��͂��Ă�������", 100.0f, 120.0f, 50.0f, c_red);

}

//�l�[�����͂̃L�[�{�[�h���當����ǂݎ��֐�
//����:���͂��ꂽ����������z��̗v�f��
//�߂�l�F�Ή����Ă���key�������ꂽ��:true ������������Ă��Ȃ����:false
bool CObjNameInput::KeyInput(int number)
{
	//EnterKey�������ꂽ�Ƃ�
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if(number==0)//�����͂̏�ԂȂ�
			m_noname_flag = true;//���͂𑣂����͂̒ǉ��p�Ƀt���O���I���ɂ���
		else
			m_name[number] = '\0';	//\0������
		return true;
	}
	
	////�o�b�N�X�y�[�X�������ꂽ�Ƃ�
	//if (Input::GetVKey(VK_BACK) == true)
	//{
	//	if (m_input_count != 0)//�����͂̏�ԂłȂ����
	//	{
	//		m_name[number] = ' ';	//�����ɂ��ǂ���
	//		m_input_count--;		//�ۑ��ʒu���ꕶ���O�ɂ��炷
	//	}
	//	return true;
	//}

	//key�̏�Ԃ𒲂ׂ�
	for (char key = 'A'; key <= 'Z'; key++)
	{
		if (Input::GetVKey(key) == true)
		{
			m_name[number] = key;	//�����ꂽkey��z��ɕۑ�
			
			if( m_input_count < 5)	//5�����ڂ܂łȂ�
				m_input_count++;		//�ۑ��ʒu���ꕶ���i�߂�

			return true;
		}
	}
	return false;
	
}

//��������͂��I����Ă��邩(\0�����邩)���ׂ�֐�
//�߂�l�F\0�������:true �Ȃ����:false 
bool CObjNameInput::InputEndCheck()
{
	//�z��̒��g���m�F���Ă���
	for (int i = 0; i < 6;i++)
	{
		//\0�������
		if (m_name[i] == '\0')
			return true;
	}

	return false;
}

//������̕������ƊԂɔ��p�󔒂������֐�
void CObjNameInput::NameCpy(char name[])
{
	int i;
	//������̔z��T�C�Y�ɂȂ�܂Ń��[�v
	for (i= 0; i < sizeof(name) * 2 + 1 ; i++)
	{
		if (i % 2 == 0)	//�v�f���������Ȃ�
			m_cpy_name[i] = m_name[i / 2];	//�z��ɓ����Ă��镶���������
		else
			m_cpy_name[i] = ' ';			//���p�󔒂������
	}

	m_cpy_name[i] = '\0';//������\0�������
}